/*
Project 3 - Part 1d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3. 
Part1 will be broken up into 5 separate steps 
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************
0) move 5-9 to between your Thing 4 and Thing 10.

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine` and 
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
*/

/*
Thing 1) Hotel
5 properties:
    1) Number of rooms
    2) Number of guests
    3) Gross revenue
    4) Overhead costs per anum
    5) Number of employees
3 things it can do:
    1) Book in guests
    2) Clean rooms
    3) Valet service
 */

/*
Thing 2) Printer
5 properties:
    1) Ink levels 
    2) Electrcity consumption rate
    3) Paper level
    4) Maximum resolution
    5) Brand name
3 things it can do:
    1) Print documents
    2) Load print jobs
    3) Scan documents
 */

/*
Thing 3) Oven
5 properties:
    1) Maximum temperature
    2) Number of trays
    3) Model ID
    4) Energy consumption rating
    5) Cost
3 things it can do:
    1) Cook food
    2) Consume electrictiy
    3) Power filiments
 */

/*
Thing 4) Music studio
5 properties:
    1) Number of microphones
    2) Available instruments
    3) Available outboard equipment
    4) Number of engineers
    5) Cost per hour
3 things it can do:
    1) Recording musicians
    2) Mix audio
    3) Master audio
 */

/*
Thing 5) Wheels
5 properties:
    1) tread depth
    2) Maximum load
    3) Maximum pressure
    4) size
    5) air pressure
3 things it can do:
    1) rotate
    2) release air
    3) adjust turning angle
 */

/*
Thing 6) Engine
5 properties:
    1) Number of cylinders
    2) Oil level
    3) Coolant level
    4) Distance driven (kms)
    5) Current RPM
3 things it can do:
    1) Fire pistons
    2) Combust fuel
    3) Propel vehicle
 */

/*
Thing 7) Trailer
5 properties:
    1) Objects held
    2) Tray size
    3) Number of wheels
    4) Maximum load (kg)
    5) Registration plate number
3 things it can do:
    1) Hold objects
    2) Dump load
    3) Disconnect from vehicle
 */

/*
Thing 8) Gear box
5 properties:
    1) Number of gears
    2) Current gear engaged
    3) Shaft rotation speed
    4) Gear wear
    5) Clutch pressure
3 things it can do:
    1) Increase torque
    2) Decrease torque
    3) Disengage gears (neutral)
 */

/*
Thing 9) Headlights
5 properties:
    1) Wattage
    2) Beam angle
    3) Houseing shape
    4) Bulb type
    5) Candela
3 things it can do:
    1) Illuminate
    2) Change intensity
    3) Adjust beam angle
 */

/*
Thing 10) Tractor
5 properties:
    1) Wheels
    2) Engine
    3) Trailer
    4) Gear box
    5) Headlights
3 things it can do:
    1) Drive
    2) Reverse
    3) Turn on lights
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
