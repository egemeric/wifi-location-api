#include "wifi_scan.h"
#include <stdio.h>	//printf
#include <unistd.h> //sleep

const char *bssid_to_string(const uint8_t bssid[BSSID_LENGTH], char bssid_string[BSSID_STRING_LENGTH])
{
	snprintf(bssid_string, BSSID_STRING_LENGTH, "%02x:%02x:%02x:%02x:%02x:%02x",
			 bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5]);
	return bssid_string;
}

const int BSS_INFOS = 50;

void Usage(char **argv);

int main(int argc, char **argv)
{
	struct wifi_scan *wifi = NULL;
	struct wifi_scan *wifi5 = NULL;
	struct bss_info bss[BSS_INFOS];
	char mac[BSSID_STRING_LENGTH];
	int status, i;
	int status5, i5;

	if (argc < 2 && argc >3)
	{
		Usage(argv);
		return 0;
	}

	wifi = wifi_scan_init(argv[1]);
	if (argc == 3)
	{
		wifi5 = wifi_scan_init(argv[2]);
		status5 = wifi_scan_all(wifi5, bss, BSS_INFOS);
		if (status5 < 0)
			perror("Unable to get scan data (second interface)");
		else
		{
			for (i5 = 0; i < status5 && i5 < BSS_INFOS; ++i)
				printf("INT2) %s %s signal %d dBm on frequency %u MHz seen %d ms ago status %s\n",
					   bssid_to_string(bss[i].bssid, mac),
					   bss[i].ssid,
					   bss[i].signal_mbm / 100,
					   bss[i].frequency,
					   bss[i].seen_ms_ago,
					   (bss[i].status == BSS_ASSOCIATED ? "associated" : ""));

			printf("\n");
		}
		wifi_scan_close(wifi5);
	}
	while (1)
	{
		status = wifi_scan_all(wifi, bss, BSS_INFOS);
		if (status < 0)
			perror("Unable to get scan data");
		else
			for (i = 0; i < status && i < BSS_INFOS; ++i)
				printf("%s %s signal %d dBm on frequency %u MHz seen %d ms ago status %s\n",
					   bssid_to_string(bss[i].bssid, mac),
					   bss[i].ssid,
					   bss[i].signal_mbm / 100,
					   bss[i].frequency,
					   bss[i].seen_ms_ago,
					   (bss[i].status == BSS_ASSOCIATED ? "associated" : ""));

		printf("\n");

		sleep(2);
	}

	wifi_scan_close(wifi);

	return 0;
}

void Usage(char **argv)
{
	printf("Usage:\n");
	printf("%s wireless_interface\n\n", argv[0]);
	printf("examples:\n");
	printf("%s wlan0\n", argv[0]);
}