 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTravelled;

    struct Foot 
    {
        float legLength = 1.2f;
        int numSteps = 0;

        void stepForward()
        {
            numSteps += 1;
        }

        float stepSize()
        {
            return legLength;
        }
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTravelled += leftFoot.stepSize() + rightFoot.stepSize();
    std::cout << "Current speed is " << howFast << "mph." << std::endl;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */

struct Hotel
{
    // Number of rooms
    int numRooms = 85;
    // Number of guests
    int numGuests = 65;
    // Gross revenue
    float grossRevenue = 300000.f;
    // Overhead costs per anum
    float overheads = 80000.f;
    // Number of employees
    int numEmployees = 20;

    struct Guest
    {
        std::string name = "Sally";
        int age = 34;
        int lengthOfStay = 4;
        int roomNumber = 67;
        float costPerNight = 120.f;

        float chargeGuest(float amount);
        void callRoom(int roomNumber);
        void endStay(std::string guestName, int roomNumber);
    };

    // Book in guests
    void bookGuests(Guest guest);
    // Clean rooms
    void cleanRoom(int roomNumber);
    // Valet service
    void valetCar(Guest guest, int parkingSpot);

    Guest sally;
};

void Hotel::bookGuests(Hotel::Guest guest)
{
    float totalCost = guest.costPerNight * guest.lengthOfStay;
    std::cout << "Total cost is: " << totalCost;

}

void Hotel::cleanRoom(int roomNumber)
{
    std::cout << "Hi, would you like room " << roomNumber <<"cleaned?";
}

void Hotel::valetCar(Hotel::Guest guest, int parkingSpot)
{
    guest.costPerNight += 20.f;
    std::cout << "Delier car to parking spot " << parkingSpot;
}

struct Printer
{
    // Ink levels
    float inkLevel = 75.f; 
    // Electrcity consumption rate
    float electrictyConsumption = 140.f;
    // Paper level
    int paperLevel = 124;
    // Maximum resolution
    int maxRes = 300;
    // Brand name
    std::string brandName = "Canon";

    struct PrintJob 
    {
        std::string documentFilename = "myDoc.doc";
        int numCopies = 2;
        int numPages = 12;
        int resolution = 300;
        std::string paperType = "A4";

        void cancelJob(std::string jobID);
        std::string checkJobStatus(std::string jobID);
        void addToQueue(std::string printerID, std::string proity = "low");
    };

    // Print documents
    void printDocument(PrintJob printJob);
    // Load print jobs
    void loadJobs(int queueNumber);
    // Scan documents
    void scanDocument(int resolution = 300);

    PrintJob currentPrintJob;
};

void Printer::printDocument(Printer::PrintJob printJob)
{
    std::cout << "Printing " << printJob.numCopies << " Copies of document" << printJob.documentFilename;
}

void Printer::loadJobs(int queueNumber)
{
    if (queueNumber > 1)
    {
        queueNumber -= 1;
    }
}

void scanDocument(int resolution = 300)
{
    std::cout << "Scanning document at " << resolution << " dpi.";
}
 
struct Oven
{
    // Maximum temperature
    float maxTemp = 350.f;
    // Number of trays
    int numTrays = 3;
    // Model ID
    std::string modelID = "N465D887";
    // Energy consumption rating
    int energyRating = 3;
    // Cost
    float cost = 1200.f;

    // Cook food
    void cookFood(float temperature, float duration);
    // Consume electrictiy
    float consumeElectricty(float intensity);
    // Power filiments
    void powerFiliments(int noFiliments = 4);
};

void Oven::cookFood(float temperature, float duration)
{
    void powerFiliments();
    float power = consumeElectricty(3.f / temperature);
    std::cout << "Cooking for " << (duration / 60) << " minutes at" << power << " powrer";
}

float Oven::consumeElectricty(float intensity)
{
    float electrictyConsumed = intensity / energyRating;
    return electrictyConsumed;
}

void Oven::powerFiliments(int noFiliments)
{
    std::cout << "Heating " << noFiliments << " filiments..";
}

struct MusicStudio
{
    // Number of microphones
    int numMics = 8;
    // Available instruments
    std::string instruments = "Gibson Guitar";
    // Available outboard equipment
    std::string outboardEquipment = "Neve 1073";
    // Number of engineers
    int numEngineers = 3;
    // Cost per hour
    float costPerHour = 350.f;

    // Recording musicians
    void recordMusicians(int numPlayers, float songDuration);
    // Mix audio
    void mixAudio(std::string audioID, float audioDuration, int numTracks);
    // Master audio
    void masterAudio(std::string audioID, float audioDuration);
};

void MusicStudio::recordMusicians(int numPlayers, float songDuration)
{
    float recordedAudioDuration = songDuration*numPlayers;
    std::cout << "Duration of audio recorded: " << recordedAudioDuration;
}

void MusicStudio::mixAudio(std::string audioID, float audioDuration, int numTracks)
{
    std::cout << "Mixing " << audioID;
    float mixCost = audioDuration * numTracks * 0.45f;
    std::cout << "Cost of mixdown: " << mixCost;
}

void MusicStudio::masterAudio(std::string audioID, float audioDuration)
{
    std::cout << "Mastering " << audioID;
    float masterCost = audioDuration * 0.45f;
    std::cout << "Cost of master: " << masterCost;
}

struct Wheel
{
    // Tread depth
    float tradDepth = 12.f;
    // Maximum load
    float maxLoad = 3450.f;
    // Maximum pressure
    float maxPressure = 35.f;
    // Size
    float size = 1.2f;
    // Current air pressure
    float currentPressure = 31.2f;

    // rotate
    void roateWheel(float amount, bool forward = true);
    // release air
    void releaseAir(float pressureAmount);
    // adjust turning angle
    void turnWheel(float angle);
};

void Wheel::roateWheel(float amount, bool forward)
{
    std::string direction = "backward";

    if (forward)
    {
        direction = "forward";
    }

    std::cout << "Moving " << direction << "by " << amount;
}

void Wheel::releaseAir(float pressureAmount)
{
    currentPressure -= pressureAmount;
}

void Wheel::turnWheel(float angle)
{
    std::cout << "Wheel turnign by " << angle << " radians ";
}

struct Engine
{
    // Number of cylinders
    int noCylinders = 4;
    // Oil level
    float oilLevel = 80.5f;
    // Coolant level
    float collantLevel = 76.2f;
    // Distance driven (kms)
    float distanceDriven = 150000;
    // Current RPM
    float currentRPM = 2457.f;

    // Fire pistons
    void firePistons(int pistonNum);
    // Combust fuel
    void combustFuel(float fuelAmount);
    // Propel vehicle
    void propelVehicle(float distance, float speed);
};

void Engine::firePistons(int pistonNum)
{
    std::cout << "Fire piston " << pistonNum;
}

void Engine::combustFuel(float fuelAmount)
{
    std::cout << fuelAmount << " fuel burnt";
}

void Engine::propelVehicle(float distance, float speed){
    float fuelRequired = distance * speed * 2.345f;
    combustFuel(fuelRequired);
    
    for (int i = 0; i < noCylinders; i++) 
    {
        firePistons(i);
    }
}

struct Trailer
{
    // Objects held
    std::string objectsHeld = "2x hay bails";
    // Tray size
    float traySize = 120.f;
    // Number of wheels
    int numWheels = 2;
    // Maximum load (kg)
    float maxLoad = 1200.f;
    // Registration plate number
    std::string registrationPlate = "EQ 1234";

    // Hold objects
    void holdObject(std::string object, int objectNum);
    // Dump load
    void dumpLoad();
    // Disconnect from vehicle
    void disconnect();
};

void Trailer::holdObject(std::string object, int objectNum)
{
    objectsHeld = objectsHeld + ", " + std::to_string(objectNum) + "x " + object;
}

void Trailer::dumpLoad()
{
    objectsHeld = "";
}

void Trailer::disconnect()
{
    std::cout << "Traielr disconnected.";
}

struct GearBox
{
    // Number of gears
    int numGears = 5;
    // Current gear engaged
    int currentGearEngaged = 3;
    // Shaft rotation speed
    float shaftRotationSpeed = 2300.f;
    // Gear wear
    float gearWear = 24.5f;
    // Clutch pressure
    float clutchPressue = 55.6f;

    // Increase torque
    void increaseTorque(float amount);
    // Decrease torque
    void decreaseTorque(float amount);
    // Disengage gears (neutral)
    void disengageGears();
};

void GearBox::increaseTorque(float amount)
{
    if ((currentGearEngaged + amount) <= numGears)
    {
        currentGearEngaged += amount;
    }
}

void GearBox::decreaseTorque(float amount)
{
    if (currentGearEngaged - amount >= 1)
    {
        currentGearEngaged -= amount;
    }
}

void GearBox::disengageGears()
{
    currentGearEngaged = 0;
}

struct Headlight
{
    // Wattage
    float wattage = 400.f;
    // Beam angle
    float beamAngle = 20.f;
    // Houseing shape
    std::string houseingShape = "round";
    // Bulb type
    std::string bulbType = "LED";
    // Candela
    float candela = 1200.f;

    // Illuminate
    float illuminate(float illuminationAmount, bool highBeams = false);
    // Change intensity
    void changeIntensity(float intenstityAmount);
    // Adjust beam angle
    void adjustBeamAngle(float newAngle);
};

float Headlight::illuminate(float illuminationAmount, bool highBeams)
{
    float illumination = illuminationAmount * 2;

    if (highBeams)
    {
        illumination += 20;
    }

    return illumination;
}

void Headlight::changeIntensity(float intenstityAmount)
{
    wattage += intenstityAmount;
}

void Headlight::adjustBeamAngle(float newAngle)
{
    beamAngle += newAngle;
} 

struct Tractor
{
    // Wheels
    Wheel wheels;
    // Engine
    Engine engine;
    // Trailer
    Trailer trailer;
    // Gear box
    GearBox gearBox;
    // Headlights
    Headlight headlights;
    
    // Drive
    void drive(Engine engine, GearBox gearBox);
    // Reverse
    void Reverse(Engine engine, GearBox gearBox);
    // Turn on lights
    void turnOnLights(Headlight headlights);
};

void Tractor::drive(Engine engineA, GearBox gearBoxA)
{
    gearBoxA.increaseTorque(1);
    engineA.propelVehicle(100, 30);
}

void Tractor::Reverse(Engine engineA, GearBox gearBoxA)
{
    gearBoxA.decreaseTorque(1);
    engineA.propelVehicle(-100, -30);
}

void Tractor::turnOnLights(Headlight headlightsA)
{
    float illumination = headlightsA.illuminate(20);
    std::cout << "Illuminating lights by " << illumination;
    // Change intensity
    headlightsA.changeIntensity(illumination);
}

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
