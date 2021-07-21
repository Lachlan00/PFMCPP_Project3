/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call some of those amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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
    void bookGuests();
    // Clean rooms
    void cleanRoom(int roomNumber);
    // Valet service
    void valetCar(int parkingSpot);

    Guest guest;
};

void Hotel::bookGuests()
{
    float totalCost = guest.costPerNight * guest.lengthOfStay;
    std::cout << "Total cost is: " << totalCost;

}

void Hotel::cleanRoom(int roomNumber)
{
    std::cout << "Hi, would you like room " << roomNumber <<"cleaned?";
}

void Hotel::valetCar(int parkingSpot)
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
    void printDocument();
    // Load print jobs
    void loadJobs(int queueNumber);
    // Scan documents
    void scanDocument(int resolution = 300);

    PrintJob printJob;
};

void Printer::printDocument()
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

void Engine::propelVehicle(float distance, float speed)
{
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
    void drive(float distance, float speed);
    // Reverse
    void reverse(float distance, float speed);
    // Turn on lights
    void turnOnLights(float initialIntensity);
};

void Tractor::drive(float distance, float speed)
{
    gearBox.increaseTorque(1);
    engine.propelVehicle(distance, speed);
}

void Tractor::reverse(float distance, float speed)
{
    gearBox.decreaseTorque(1);
    engine.propelVehicle(-distance, -speed);
}

void Tractor::turnOnLights(float initialIntensity)
{
    float illumination = headlights.illuminate(initialIntensity);
    std::cout << "Illuminating lights by " << illumination;
    // Change intensity
    headlights.changeIntensity(illumination);
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
    Example::main();
    std::cout << "good to go!" << std::endl;
}
