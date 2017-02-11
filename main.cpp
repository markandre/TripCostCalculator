/*This is a program by Mark Andre.
  It was compiled on January 15, 2015.
  It is designed to help calculate commute costs
  to see whether public transportation is cheaper
  than driving under various scenarios.
*/
#include <iostream>

using namespace std;

//CONSTANTS
const double TRAIN_FARE = 2.25;//cost of one time entry to Metro Rail
const double TRAIN_DAY = 5.65;//cost of day pass to Metro Rail
const double TRAIN_MONTH = 112.50;//cost of one month pass to Metro Rail

const double TOLL = 0.35;//cost of each toll on highway 112
const double TRIP_LENGTH = 9.5;//length of either going to or coming from school in miles


//FUNCTION PROTOTYPES
int menu();
void results(int, double, double, double, double, double);

int main()
{
    //GET INITAL INFO
    int weekTrips = 0;//Trips in a week
    cout << "Enter the number of trips taken in a week, each way:";
    cin >> weekTrips;
    double mpg = 0.0;//Miles per gallon
    cout << "Enter the average miles per gallon you expect to get:";
    cin >> mpg;
    double ppg = 0.0;//Price per gallon
    cout << "Enter the expected average cost of gas:$";
    cin >> ppg;

    int userchoice;

    do
    {
        //RESULTS
        double weekTollCost = TOLL * 2 * weekTrips;
        double galTrip = TRIP_LENGTH / mpg;//gallons per trip
        double gasCost = galTrip * ppg;
        double weekGasCost = gasCost * weekTrips;
        double weekTripCost = weekTollCost + weekGasCost;
        double monthCost = weekTripCost * 4;

        results(weekTrips, weekTollCost, weekGasCost, weekTripCost, monthCost, galTrip);

        userchoice = menu();

        switch (userchoice)
        {
        case 1:
            cout << "Enter the new number of trips per week:";
            cin >> weekTrips;
            break;
        case 2:
            cout << "Enter the new expected MPG:";
            cin >> mpg;
            break;
        case 3:
            cout << "Enter the new expected average cost of gas";
            cin >> ppg;
            break;
        default:
            break;
        }

    }while (userchoice != 0);




    return 0;
}

int menu()
{
    int userchoice;
    cout << "Which variable do you want to change?" << endl;
    cout << "1.Trips per week." << endl;
    cout << "2.MPG." << endl;
    cout << "3.Cost of gas." << endl;
    cout << "0.Exit." << endl;
    cin >> userchoice;

    return userchoice;

}

void results(int weekTrips, double weekTollCost, double weekGasCost, double weekTripCost, double monthCost, double galTrip)
{
    cout << "Weekly cost of tolls: $" << weekTollCost << endl;
    cout << "Weekly cost of gas: $" << weekGasCost << endl;
    cout << "Weekly car travel cost: $" << weekTripCost << endl;
    cout << "Monthly car travel cost: $" << monthCost << endl;
    cout << endl;
    cout << "Taking the metro at standard fare every day would cost $" << TRAIN_FARE * weekTrips
         << " per week, \nand $" << TRAIN_FARE * weekTrips * 4 << " per month." << endl;
    cout << endl;
    cout << "There is a monthly pass available that costs $112.50 per month. \nBuying this would mean you are paying $"
         << TRAIN_MONTH / (weekTrips * 4) << " per trip, \nwhich is $" << (TRAIN_MONTH / (weekTrips * 4)) - TRAIN_FARE
         << " more than standard fare." << endl;
    cout << "Gas would have to cost $" << ((TRAIN_FARE * weekTrips) - weekTollCost)/(galTrip * weekTrips) << " per gallon \nfor it to be cheaper to take the train." << endl;
}























