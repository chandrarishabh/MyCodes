import turtle

def fractal(rish,distance,angle):
	if(distance<5):
		rish.color('green')
		rish.stamp()
		rish.color('brown')
	else:
		rish.forward(distance)
		rish.right(angle)
		fractal(rish,distance-15,angle)
		rish.left(2*angle)
		fractal(rish,distance-15,angle)
		rish.right(angle)
		rish.forward(-distance)		
		

def main():
	window = turtle.Screen()
	window.bgcolor('lightblue')
	rish = turtle.Turtle()
	rish.shape('circle')
	rish.left(90)
	rish.color('darkblue')
	rish.speed(1000)
	rish.pensize(2)
	fractal(rish,100,35)
	window.exitonclick()

main()