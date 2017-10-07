import turtle
 
def Circle(rish,In,Mid,Out,in_radius,gap,out_radius):
	for i in range(360):
		rish.down()
		rish.left(i)
		rish.color(In)
		rish.forward(in_radius)
		rish.color(Mid)
		rish.forward(gap)
		rish.color(Out)
		rish.forward(out_radius)
		rish.up()
		rish.home()



def main():
	window=turtle.Screen()
	window.bgcolor('lightblue')
	rish=turtle.Turtle()
	rish.speed(100)
	rish.hideturtle()
	Circle(rish,'green','white','orange',50,50,50)
	window.exitonclick()
 
main()