import turtle

def main():
	window = turtle.Screen()
	window.bgcolor('lightblue')
	rish = turtle.Turtle()
	rish.left(90)
	rish.color('darkblue')
	rish.speed(10000)
	rish.pensize(2)
	
	for i in range(360):
		rish.color('yellow')
		rish.forward(50)
		rish.color('orange')
		rish.right(30)	
		rish.forward(100)
		rish.color('red')
		rish.left(60)
		rish.forward(150)
		rish.right(30)
		rish.up()
		rish.setposition(0,0)
		rish.down()
		rish.right(1)


	window.exitonclick()

main()