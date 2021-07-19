/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


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
    1) tyres
    2) hubcaps
    3) bolts
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
