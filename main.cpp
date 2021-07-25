/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()
#include <math.h> //for rounding

struct Hotel
{
    int numRooms, numGuests, numEmployees;
    float grossRevenue, overheads;
    Hotel();

    struct Guest
    {
        int age, lengthOfStay, roomNumber;
        float costPerNight;
        std::string name;
        Guest();

        float chargeGuest(float amount);
        void callRoom(int roomNumber);
        void endStay(std::string guestName, int roomNumber);
    };

    void bookGuests();
    void cleanRoom(int roomNumber);
    void valetCar(int parkingSpot);
    void layOffEmployees(int numFired);

    Guest guest;
};

Hotel::Hotel() :
numRooms(85),
numGuests(65),
numEmployees(20),
grossRevenue(300000.f),
overheads(80000.f)
{}

Hotel::Guest::Guest() :
age(34),
lengthOfStay(4),
roomNumber(67),
costPerNight(120.f),
name("Sally")
{}

void Hotel::bookGuests()
{
    float totalCost = guest.costPerNight * guest.lengthOfStay;
    std::cout << "Total cost is: $" << totalCost << std::endl;
    std::cout << "I hope you enjoy staying in our Hotel! Please let usk know if your room is not to your liking! We currently have " << numRooms - numGuests << " available." << std::endl;

}

void Hotel::cleanRoom(int roomNumber)
{
    std::cout << "Hi, would you like room " << roomNumber <<" cleaned?" << std::endl;
}

void Hotel::valetCar(int parkingSpot)
{
    guest.costPerNight += 20.f;
    std::cout << "Deliver car to parking spot " << parkingSpot << std::endl;
}

void Hotel::layOffEmployees(int numFired)
{
    if (grossRevenue < overheads)
    {
        std::cout << "Times are tough.." << std::endl;
        
        for (int i = 0; i < numFired; ++i)
        {
            std::cout << "Employee " << i + 1 << " fired.." << std::endl;
        }
    }
}

struct Printer
{
    int paperLevel, maxRes;
    float inkLevel, electrictyConsumption;
    std::string brandName;
    Printer();

    struct PrintJob 
    {
        int numCopies, numPages, resolution;
        std::string documentFilename, paperType;
        PrintJob();

        void cancelJob(std::string jobID);
        std::string checkJobStatus(std::string jobID);
        void addToQueue(std::string printerID, std::string proity = "low");
    };

    void printDocument();
    void loadJobs(int queueNumber);
    void scanDocument(int resolution = 300);
    void printCopies(int noCopies);

    PrintJob printJob;
};

Printer::Printer() :
paperLevel(124),
maxRes(300),
inkLevel(75.f),
electrictyConsumption(140.f),
brandName("Canon")
{}

Printer::PrintJob::PrintJob() :
numCopies(2),
numPages(12),
resolution(300),
documentFilename("myDoc.doc"),
paperType("A4")
{}

void Printer::printDocument()
{
    std::cout << "Printing " << printJob.numCopies << " Copies of document " << printJob.documentFilename << std::endl;
    std::cout << "Current ink level: " << inkLevel << std::endl;
    std::cout << "Current paper level: "  << paperLevel << std::endl;
}

void Printer::loadJobs(int queueNumber)
{
    if (queueNumber > 1)
    {
        queueNumber -= 1;
    }
}

void Printer::scanDocument(int resolution)
{
    std::cout << "Scanning document at " << resolution << " dpi." << std::endl;
    std::cout << "Max resolution is " << maxRes << " dpi." << std::endl;
}

void Printer::printCopies(int noCopies)
{
    printJob.numCopies = noCopies;
    printDocument();
    for (int i = 0; i < noCopies; ++i)
    {
        if (paperLevel == 0)
        {
            std::cout << "Error: no paper!" << std::endl;
            break;
        }
        
        std::cout << "Printing copy " << i + 1 << ".." << std::endl;
        paperLevel -= 1;
    }
}
 
struct Oven
{
    int numTrays, energyRating;
    float maxTemp, cost;
    std::string modelID;
    Oven();

    void cookFood(float temperature, float duration);
    float consumeElectricty(float intensity);
    void powerFiliments(int noFiliments = 4);
    void turnOffFiliments(int noFiliments = 4);
};

Oven::Oven() :
numTrays(3),
energyRating(3),
maxTemp(350.f),
cost(1200.f),
modelID("N465D887")
{}

void Oven::cookFood(float temperature, float duration)
{
    void powerFiliments();
    float power = consumeElectricty(3.f / temperature);
    std::cout << "Cooking for " << (duration / 60) << " minutes at " << power << " power" << std::endl;
    std::cout << "Enjoy using this Oven! Model ID: " << modelID << std::endl;
}

float Oven::consumeElectricty(float intensity)
{
    float electrictyConsumed = intensity / energyRating;
    return electrictyConsumed;
}

void Oven::powerFiliments(int noFiliments)
{
    std::cout << "Heating " << noFiliments << " filiments.." << std::endl;
    std::cout << "Maximum temperature is " << maxTemp << " degrees celcius." << std::endl;
}

void Oven::turnOffFiliments(int noFiliments)
{
    int i = 0;
    
    while (i < noFiliments)
    {
        std::cout << "Shutting off filiment " << i + 1 << std::endl;
        ++i;
    }
}

struct MusicStudio
{
    int numMics, numEngineers;
    float costPerHour;
    std::string instruments;
    std::string outboardEquipment;
    MusicStudio();

    void recordMusicians(int numPlayers, float songDuration);
    void mixAudio(std::string audioID, float audioDuration, int numTracks);
    void masterAudio(std::string audioID, float audioDuration);
    void payEngineers();
};

MusicStudio::MusicStudio() :
numMics(8),
numEngineers(3),
costPerHour(350.f),
instruments("Gibson Guitar"),
outboardEquipment("Neve 1073")
{}

void MusicStudio::recordMusicians(int numPlayers, float songDuration)
{
    float recordedAudioDuration = songDuration*numPlayers;
    std::cout << "Duration of audio recorded: " << recordedAudioDuration << std::endl;
    std::cout << "Cost per hour is: $" << costPerHour << std::endl;
}

void MusicStudio::mixAudio(std::string audioID, float audioDuration, int numTracks)
{
    std::cout << "Mixing " << audioID;
    float mixCost = audioDuration * numTracks * 0.45f;
    std::cout << "! Cost of mixdown: $" << mixCost << std::endl;
}

void MusicStudio::masterAudio(std::string audioID, float audioDuration)
{
    std::cout << "Mastering " << audioID;
    float masterCost = audioDuration * 0.45f;
    std::cout << "! Cost of master: $" << masterCost << std::endl;
    std::cout << "We added some sweet harmonics to your tracks using the " << outboardEquipment << "!" << std::endl;
}

void MusicStudio::payEngineers()
{
    int i = 0;
    
    while (i < numEngineers)
    {
        std::cout << "Engineer " << i + 1 << " paid $" << costPerHour/2 << std::endl;
        ++i;
    }
}

struct Wheel
{
    float tradDepth, maxLoad, maxPressure, size, currentPressure;
    Wheel();

    void roateWheel(float amount, bool forward = true);
    void releaseAir(float pressureAmount);
    void turnWheel(float angle);
    void maximisePressure(float pressureIncrement = 2);
};

Wheel::Wheel() :
tradDepth(12.f),
maxLoad(3450.f),
maxPressure(35.f),
size(1.2f),
currentPressure(31.2f)
{}

void Wheel::roateWheel(float amount, bool forward)
{
    std::string direction = "backward ";

    if (forward)
    {
        direction = "forward ";
    }

    std::cout << "Moving " << direction << "by " << amount << std::endl;
}

void Wheel::releaseAir(float pressureAmount)
{
    currentPressure -= pressureAmount;
    std::cout << pressureAmount << " PSI of air released!" << std::endl;
    std::cout << "Max pressure: " << maxPressure << " psi" << std::endl;
}

void Wheel::turnWheel(float angle)
{
    std::cout << "Wheel turnign by " << angle << " radians" << std::endl;
    std::cout << "The wheel has " << tradDepth << " mm left of tread." << std::endl;
}

void Wheel::maximisePressure(float pressureIncrement)
{
    while (currentPressure < maxPressure)
    {
        std::cout << "Adding " << pressureIncrement << " psi.." << std::endl;
        currentPressure += pressureIncrement;
        std::cout << "Current pressure is " << currentPressure << std::endl;
    }
    
    if (currentPressure > maxPressure)
    {
        std::cout << "WARNING! Too much pressure. Releasing air.." << std::endl;
        releaseAir(currentPressure - maxPressure);
    }
}

struct Engine
{
    int noCylinders;
    float oilLevel, collantLevel, distanceDriven, currentRPM;
    Engine();

    void firePistons(int pistonNum);
    void combustFuel(float fuelAmount);
    void propelVehicle(float distance, float speed);
    void adjustOil(float desiredLevel);
};

Engine::Engine() :
noCylinders(4),
oilLevel(80.f),
collantLevel(76.2f),
distanceDriven(150000),
currentRPM(2457.f)
{}

void Engine::firePistons(int pistonNum)
{
    std::cout << "Fire piston " << pistonNum + 1 << std::endl;
}

void Engine::combustFuel(float fuelAmount)
{
    std::cout << fuelAmount << " fuel burnt" << std::endl;
    std::cout << "Current oil livel: " << oilLevel << std::endl;
}

void Engine::propelVehicle(float distance, float speed)
{
    float fuelRequired = distance * speed * 2.345f;
    combustFuel(fuelRequired);
    std::cout << "This engine has " << noCylinders << " cylinders. Fire the pistons!" << std::endl;
    
    for (int i = 0; i < noCylinders; ++i) 
    {
        firePistons(i);
    }
}

void Engine::adjustOil(float desiredLevel)
{
    std::cout << "Oil level: " << oilLevel << std::endl;
    std::cout << (desiredLevel >= oilLevel ? "Adding ":"Removing") << " oil" << std::endl;
    
    if (desiredLevel > 100.f)
    {
        desiredLevel = 100.f;
    }

    while (oilLevel < desiredLevel)
    {
        oilLevel += 5;
        std::cout << "Adding oil.. current level: " << oilLevel << std::endl; 
    }

    while (oilLevel > desiredLevel)
    {
        oilLevel -= 5;
        std::cout << "Removing oil.. current level: " << oilLevel << std::endl; 
    }
}

struct Trailer
{
    int numWheels;
    float traySize, maxLoad;
    std::string objectsHeld, registrationPlate;
    Trailer();

    void holdObject(std::string object, int objectNum);
    void dumpLoad();
    void disconnect();
    void takeOffWheels();
};

Trailer::Trailer() :
numWheels(2),
traySize(120.f),
maxLoad(1200.f),
objectsHeld("2x hay bails"),
registrationPlate("EQ 1234")
{}

void Trailer::holdObject(std::string object, int objectNum)
{
    if (objectsHeld == "")
    {
        objectsHeld = std::to_string(objectNum) + "x " + object;
    }
    else
    {
        objectsHeld = objectsHeld + ", " + std::to_string(objectNum) + "x " + object;
    }
}

void Trailer::dumpLoad()
{
    objectsHeld = "";
}

void Trailer::disconnect()
{
    std::cout << "Trailer disconnected." << std::endl;
    std::cout << "Registration plate is: " << registrationPlate << std::endl;
}

void Trailer::takeOffWheels()
{
    std::cout << "Removing wheels!" << std::endl;
    
    for (int i = 0; i < numWheels; ++i)
    {
        std::cout << "Wheel " << i+1 << " removed.." << std::endl;
    }
}

struct GearBox
{
    int numGears, currentGearEngaged;
    float shaftRotationSpeed, gearWear, clutchPressue;
    GearBox();

    void increaseTorque(float amount);
    void decreaseTorque(float amount);
    void disengageGears();
    void shiftGears(int targetGear);
};

GearBox::GearBox() :
numGears(5),
currentGearEngaged(3),
shaftRotationSpeed(2300.f),
gearWear(24.5f),
clutchPressue(55.6f)
{}

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

void GearBox::shiftGears(int targetGear)
{
    if (targetGear > numGears)
    {
        targetGear = numGears;
    }
    else if (targetGear < 0)
    {
        targetGear = 0;
    }
    
    while (currentGearEngaged != targetGear)
    {
        if (currentGearEngaged < targetGear)
        {
            std::cout << "Shifting up!" << std::endl;
            currentGearEngaged += 1;
            std::cout << "Current gear: " << currentGearEngaged << std::endl;
        } 
        else
        {
            std::cout << "Shifting down!" << std::endl;
            currentGearEngaged -= 1;
            std::cout << "Current gear: " << currentGearEngaged << std::endl;
        } 
    }
}

struct Headlight
{
    int maxBeamPower;
    float wattage, beamAngle, candela;
    std::string houseingShape, bulbType;
    Headlight();

    float illuminate(float illuminationAmount, bool highBeams = false);
    void changeIntensity(float intenstityAmount);
    void adjustBeamAngle(float newAngle);
    void lightBeamWeapon(float beamPower);
};

Headlight::Headlight() :
maxBeamPower(9000),
wattage(400.f),
beamAngle(20.f),
candela(1200.f),
houseingShape("round"),
bulbType("LED")
{}

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

void Headlight::lightBeamWeapon(float beamPower)
{   
    float progBarMaxLength = 50;
    float prog = 0;
    
    if (beamPower > maxBeamPower)
    {
        beamPower = maxBeamPower;
    }
    else if (beamPower <= 0)
    {
        beamPower = 1;
    }
    
    std::cout << "Charging light beam to " << beamPower <<"! Full power is " << maxBeamPower << " watts!" << std::endl;

    for (float power = 1; power <= beamPower; power++)
    {
        prog = (power/beamPower) * progBarMaxLength;
        std::cout << "Charging [" << round((power/beamPower)*100) << "%]\r" << std::flush;
    }
    
    std::cout << std::endl << std::endl << "FIRE!!!!" << std::endl << std::endl;
}

struct Tractor
{
    Wheel wheels;
    Engine engine;
    Trailer trailer;
    GearBox gearBox;
    Headlight headlights;
    Tractor();
    
    void drive(float distance, float speed);
    void reverse(float distance, float speed);
    void turnOnLights(float initialIntensity);
};

Tractor::Tractor()
{
    std::cout << "Tractor willed into existence!" << std::endl;
}

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
    std::cout << "Illuminating lights by " << illumination << std::endl;
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
    //Example::main();
    std::cout << std::endl;

    Hotel hotel;
    hotel.bookGuests();
    hotel.cleanRoom(12);
    hotel.valetCar(27);
    hotel.layOffEmployees(5);
    hotel.grossRevenue = 20000;
    hotel.layOffEmployees(5);

    std::cout << std::endl;

    Printer printer;
    printer.printDocument();
    printer.scanDocument(72);
    printer.printCopies(3);
    printer.paperLevel = 2;
    printer.printCopies(7);

    std::cout << std::endl;

    Oven oven;
    oven.powerFiliments();
    oven.cookFood(180.f, 1200.f);
    oven.turnOffFiliments(4);

    std::cout << std::endl;

    MusicStudio musicStudio;
    musicStudio.recordMusicians(5, 185.f);
    musicStudio.mixAudio("Greatest Song", 185.f, 7);
    musicStudio.masterAudio("Greatest Song", 185.f);
    musicStudio.payEngineers();

    std::cout << std::endl;

    Wheel frontRightWheel;
    Wheel backLeftWheel;
    frontRightWheel.roateWheel(360.f);
    std::cout << "Wheel pressure: " << frontRightWheel.currentPressure << std::endl;
    frontRightWheel.releaseAir(5.f);
    std::cout << "Wheel pressure: " << frontRightWheel.currentPressure << std::endl;
    std::cout << "Wheel pressure: " << backLeftWheel.currentPressure << std::endl;
    backLeftWheel.releaseAir(7.2f);
    std::cout << "Wheel pressure: " << backLeftWheel.currentPressure << std::endl;
    backLeftWheel.turnWheel(20.f);
    backLeftWheel.maximisePressure();
    frontRightWheel.maximisePressure();

    std::cout << std::endl;

    Engine engine;
    engine.propelVehicle(100.f, 40.f);
    engine.adjustOil(50.f);
    engine.adjustOil(75.f);

    std::cout << std::endl;

    Trailer trailer;
    std::cout << "Trailer holds " << trailer.objectsHeld << std::endl;
    trailer.holdObject("Milk crate", 3);
    std::cout << "Trailer holds " << trailer.objectsHeld << std::endl;
    trailer.holdObject("Apple crate", 12);
    std::cout << "Trailer holds " << trailer.objectsHeld << std::endl;
    trailer.dumpLoad();
    std::cout << "Trailer holds " << (trailer.objectsHeld == "" ? "Nothing!" : trailer.objectsHeld) << std::endl;
    trailer.disconnect();
    trailer.takeOffWheels();

    std::cout << std::endl;

    GearBox gearBox;
    std::cout << "Current gear engaged: " << gearBox.currentGearEngaged << std::endl;
    gearBox.increaseTorque(2);
    std::cout << "Current gear engaged: " << gearBox.currentGearEngaged << std::endl;
    gearBox.disengageGears();
    std::cout << "Current gear engaged: " << gearBox.currentGearEngaged << std::endl;
    gearBox.shiftGears(5);
    gearBox.shiftGears(3);

    std::cout << std::endl;

    Tractor tractor;
    tractor.drive(120, 40);
    tractor.reverse(50, 10);
    tractor.turnOnLights(20);
    std::cout << std::endl;
    tractor.headlights.lightBeamWeapon(9000);

    std::cout << "good to go!" << std::endl;
}
