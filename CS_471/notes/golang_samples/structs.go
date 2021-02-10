package main

import "fmt"

type Person struct {
	first_name string
	last_name string
	studentID int
	mealplan_balance float64

}
func (p Person) getID() int {
  return p.studentID
}

func main() {
	var student1 Person = Person{"John", "Doe", 12345, 1.10}
	fmt.Println(student1) // output: {John Doe 12345 1.1}
    fmt.Println(student1.getID()) // output: 12345
}

