package models

type WifiScanGeoModel struct {
	LON  float32 `json:"lon"`
	LAT  float32 `json:"lat"`
	ALT  float32 `json:"alt"`
	HDOP float32 `json:"hdop"`
}

type WifiScanModel struct {
	ESSID   string             `json:"ssid"`
	BSSID   string             `json:"bssid"`
	SIGNAL  uint32             `json:"signal"`
	FREQ    uint32             `json:"freq"`
	GEODATA []WifiScanGeoModel `json:"geodata"`
}
