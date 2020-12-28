#include "Flight.h"

void free(Flight* f);
void main() 
{
	while (true)
	{

		try {

			////capsule standard class:
			Capsule cr(50, 150);
			for (int i = 0; i < 3; i++)
				cr.operator+=(*(new AirlineTicket));
			cr.operator-=(*(cr.getTickets()[1]));

			//capsule first class:
			Person bartender("123456789", "Maayan", BARTENDER);
			First fc(bartender, 3, 550, true, true);
			for (int i = 0; i < 3; i++)
				fc.operator+=(*(new AirlineTicket()));
			
			DateTime departure(2020, 12, 30, 10, 30);
			DateTime arrival(2020, 1, 31, 22, 30);

			////build flight:
			Flight f1(cr, fc, 6, "New York", departure, arrival);
			Person ploit("741852963", "Noa", PILOT);
			Person stewardess1("159753852", "Moria", STEWARDESS);
			Person stewardess2("159705652", "sapir", STEWARDESS);
			Person stewardess3("159025463", "neta", STEWARDESS);
			f1.operator+=(ploit);
			f1.operator+=(stewardess1);
			f1.operator+=(stewardess2);
			f1.operator+=(stewardess3);
			f1.operator-=(stewardess2);
			cout << f1;

			int availableFirst = f1.getCapsuleFirstClass();

			int availableCapsule = f1.getCapsuleClassRegular();

			cout << endl << "Number of available seats on flight number " << f1.getFlightId() << " in first class capsule is: " << availableFirst<<endl;
			cout << endl << "Number of available seats on flight number " << f1.getFlightId() << " in standard class capsule is: " << availableCapsule<<endl;
			
		}
		catch (invalid_argument& ex)
		{
			cout << ex.what() << " Try Again!\n";
			continue;
		}
		catch (out_of_range& ex)
		{
			cout << ex.what() << " Try Again!\n";
			continue;
		}
		catch (logic_error& ex)
		{
			cout << ex.what() << " Try Again!\n";
			continue;
		}
		catch(const char* x)
		{
			cout << x << " Try Again!\n";
			continue;
		}
		catch (...)
		{
			cout << " Unknown Error as been made, please contact administaror" << ", Try again!\n";
			continue;
		}
		break;
	}
	
}
