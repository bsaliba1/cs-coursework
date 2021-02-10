package main

import (
  "fmt"
  "time"
)

func pinger(c chan<- string) {
  for i := 0; ; i++ {
    c <- "ping" //send "ping" to string channel c
  }
}

func ponger(c chan<- string) {
  for i := 0; ; i++ {
    c <- "pong" //send pong message to channel c
  }
}

func pongest(c chan string) {
  for i := 0; ; i++ {
    c <- "pongest" //send pong message to channel c
  }
}

func printer(c <-chan string) {
  for {
    msg := <- c //receive "ping" string from c channel
    fmt.Println(msg)
    time.Sleep(time.Second * 1)
  }
}

func main() {
  var c chan string = make(chan string)

  go pinger(c)
  go ponger(c)
  go printer(c)

  var input string
  fmt.Scanln(&input)
}
