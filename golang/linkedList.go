package main

import (
	"fmt"
)

type Node struct {
	data     int
	nextNode *Node
}

type LinkedList struct {
	head *Node
}

func main() {
	ll := LinkedList{nil}
	ll.InsertBeginning(1)
	ll.InsertBeginning(2)
	ll.InsertBeginning(3)
	ll.InsertBeginning(4)
	ll.Display()
	ll.DeleteNode(1) 
	ll.DeleteNode(7) 
	ll.DeleteNode(4) 
	ll.DeleteNode(3) 
	ll.Display()
}

func (ll *LinkedList) DeleteNode(value int) {
	current := ll.head
	if current.data == value {
		ll.head = current.nextNode
		fmt.Println("Value removed successfully")
		return
	}
	for current.nextNode != nil {
		if current.nextNode.data == value {
			current.nextNode = current.nextNode.nextNode
			fmt.Println("Value removed successfully")
			return
		}
		current = current.nextNode
	}
	fmt.Println("Couldn't find value in list")
}

func (ll *LinkedList) Display() {
	current := ll.head
	for current != nil {
		fmt.Println("Current node value:", current.data)
		current = current.nextNode
	}
}

func (ll *LinkedList) InsertBeginning(value int) {
	newNode := CreateNode(value)
	newNode.nextNode = ll.head
	ll.head = &newNode
}

func CreateNode(data int) Node {
	return Node{data, nil}
}
