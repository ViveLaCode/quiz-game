package main

import (
	"log"
	"math/rand"
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/laughingclouds/quizgame/api"
	"github.com/laughingclouds/quizgame/auth"
	"github.com/laughingclouds/quizgame/db"
)

func main() {
	db.Open()
	rand.Seed(time.Now().UnixNano())
	auth.UserSession.Start("None", 0)
	server := gin.Default()

	server.StaticFS("/static/", http.Dir("./static"))

	// For front-end
	server.GET("/", index)
	server.GET("/quiz/start", index)
	server.GET("/quiz/score", index)

	// Both
	server.GET("/api/logout", api.Logout)
	server.POST("/api/logout", api.Logout)

	// For backend
	server.POST("/api/createuser", api.CreateUser)
	server.POST("/api/login", api.Login)
	server.POST("/api/calculatescore", api.CalculateScore)
	server.GET("/api/score", api.Score)
	// json responses
	server.GET("/api/sessioninfo", api.SessionInfo)
	server.GET("/api/leaderboard", api.LeaderboardData)
	server.GET("/api/categories/all", api.AllCategories)
	server.GET("/api/categories/:categoryId", api.Category)
	server.GET("/api/questions/:categoryId", api.Question)
	server.GET("/api/questions/:categoryId/answered", api.Answered)

	log.Fatal(server.Run())
}

func index(c *gin.Context) {
	log.Printf("Session: %v", auth.UserSession)
	c.File("index.html")
}
