package controllers

import (
	"fmt"
	"wifi-location-api/models"

	"github.com/gin-gonic/gin"
)

func Index(c *gin.Context) {
	wifiData := &models.WifiScanModel{
		ESSID:  "EGEMERIC2",
		BSSID:  "52:ff:dd:dd:dd:dd",
		SIGNAL: 12,
		GEODATA: []models.WifiScanGeoModel{
			{
				LON:  0.0,
				LAT:  0.0,
				HDOP: 0.0,
				ALT:  0.0,
			},
		},
	}

	fmt.Println(wifiData)
	c.JSON(200, wifiData)
}
