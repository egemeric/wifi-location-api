package main

import (
	"wifi-location-api/controllers"

	"github.com/gin-gonic/gin"
)

func main() {

	r := gin.Default()
	r.GET("/", controllers.Index)
	r.Run() // listen and serve on 0.0.0.0:8080 (for windows "localhost:8080")
}
