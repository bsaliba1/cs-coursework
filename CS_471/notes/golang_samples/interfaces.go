package main

import (
    "fmt"
)

// Interface
type Animal interface{
    speak()
}

// Types
type Cow struct{
    greeting string
}
type Bird struct{
    greeting string
}
type Cat struct{
	greeting string
}

// Implemented type methods
func(c Cow) speak(){
    fmt.Println(c.greeting)
}
func(b Bird) speak(){
    fmt.Println(b.greeting)
}
func(c Cat) meow(){
	fmt.Println(c.greeting)
}

// Function to use interface
func greetAnimal(a Animal){
    a.speak()
}

func main() {
    var cow = Cow{"Moo"}
    var bird Bird = Bird{"Caw caw"}

    greetAnimal(cow)
    greetAnimal(bird)

    // Compile time error when trying to use interface with type that doesn't have all implemented methods
    /*
    var cat Cat = Cat{"meow"}
    greetAnimal(cat) //error Cat type doesn't implement all Animal methods
    */
}
