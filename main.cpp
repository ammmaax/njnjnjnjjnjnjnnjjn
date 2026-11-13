#include<iostream>
#include<string>
using namespace std;

class Transport
{
protected:
  int koleso = 2;
  string model;
  int year;
  string color;
  double price;
public:
  Transport(){}
  virtual ~Transport(){}
  virtual void Fill() = 0;
  void Init(string md, int yr, string col, double pr)
  {
    koleso = 2;
    model = md;
    year = yr;
    color = col;
    price = pr;
  }
  virtual void Print()
  {
    cout << "Number of wheels: " << koleso << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Color: " << color << endl;
    cout << "Price: " << price << endl;
  }
  virtual void MaxSpeed() = 0;
  virtual void FuelConsumption() = 0;
  virtual void Wheels() = 0;
  virtual void Passengers() = 0;
};

class Bicycle: public Transport
{
  string brand;
  int gears;
public:
  Bicycle(){}
  void Fill() override { Init("Trek Marlin 5", 2023, "blue", 720, "Trek", 21); }
  void Init(string md, int yr, string col, double pr, string br, int gr)
  {
    Transport::Init(md,yr,col,pr);
    brand = br;
    gears = gr;
  }
  void Print() override
  {
    Transport::Print();
    cout << "Brand: " << brand << endl;
    cout << "Gears: " << gears << endl << endl;
  }
  void MaxSpeed() override { cout << "Max speed: 30 km/h" << endl; }
  void FuelConsumption() override { cout << "Fuel consumption: 0 l/100km (no engine)" << endl; }
  void Wheels() override { cout << "Wheels: " << koleso << endl; }
  void Passengers() override { cout << "Passengers: 1" << endl; }
};

class Motorcycle: public Transport
{
  string brand;
  double enginevolume;
public:
  Motorcycle(){}
  void Fill() override { Init("Honda CBR500R", 2021, "red", 7800, "Honda", 500); }
  void Init(string md, int yr, string col, double pr, string br, double eng)
  {
    Transport::Init(md,yr,col,pr);
    brand = br;
    enginevolume = eng;
  }
  void Print() override
  {
    Transport::Print();
    cout << "Brand: " << brand << endl;
    cout << "Engine volume: " << enginevolume << "cc" << endl << endl;
  }
  void MaxSpeed() override { cout << "Max speed: 190 km/h" << endl; }
  void FuelConsumption() override { cout << "Fuel consumption: 4.5 l/100km" << endl; }
  void Wheels() override { cout << "Wheels: " << koleso << endl; }
  void Passengers() override { cout << "Passengers: 2" << endl; }
};

class Sedan: public Transport
{
  int doors;
  double trunkvolume;
public:
  Sedan(){}
  void Fill() override { Init("Audi A4", 2018, "black", 17500, 4, 480); }
  void Init(string md, int yr, string col, double pr, int dr, double trunk)
  {
    Transport::Init(md,yr,col,pr);
    koleso = 4;
    doors = dr;
    trunkvolume = trunk;
  }
  void Print() override
  {
    Transport::Print();
    cout << "Doors: " << doors << endl;
    cout << "Trunk volume: " << trunkvolume << "l" << endl << endl;
  }
  void MaxSpeed() override { cout << "Max speed: 240 km/h" << endl; }
  void FuelConsumption() override { cout << "Fuel consumption: 7.0 l/100km" << endl; }
  void Wheels() override { cout << "Wheels: " << koleso << endl; }
  void Passengers() override { cout << "Passengers: 5" << endl; }
};

class Jeep: public Transport
{
  double height;
  int passengers = 7;
public:
  Jeep(){}
  void Fill() override { Init("Audi Q5", 2020, "gray", 42000, 178); }
  void Init(string md, int yr, string col, double pr, double hei)
  {
    Transport::Init(md,yr,col,pr);
    koleso = 4;
    height = hei;
    passengers = 7;
  }
  void Print() override
  {
    Transport::Print();
    cout << "Height: " << height << "sm" << endl;
    cout << "Passengers: " << passengers << endl << endl;
  }
  void MaxSpeed() override { cout << "Max speed: 230 km/h" << endl; }
  void FuelConsumption() override { cout << "Fuel consumption: 8.5 l/100km" << endl; }
  void Wheels() override { cout << "Wheels: " << koleso << endl; }
  void Passengers() override { cout << "Passengers: " << passengers << endl; }
};

class Bus: public Transport
{
  string road;
  int seats;
  bool lowFloor;
public:
  Bus(){}
  void Fill() override { Init("Volvo 7900", 2019, "white", 135000, "Route 15", 50, false); }
  void Init(string md, int yr, string col, double pr, string rd, int st, bool low)
  {
    Transport::Init(md,yr,col,pr);
    koleso = 6;
    road = rd;
    seats = st;
    lowFloor = low;
  }
  void Print() override
  {
    Transport::Print();
    cout << "Road: " << road << endl;
    cout << "Seats: " << seats << endl;
    cout << "Low floor: " << lowFloor << endl << endl;
  }
  void MaxSpeed() override { cout << "Max speed: 100 km/h" << endl; }
  void FuelConsumption() override { cout << "Fuel consumption: 30 l/100km" << endl; }
  void Wheels() override { cout << "Wheels: " << koleso << endl; }
  void Passengers() override { cout << "Passengers: " << seats << endl; }
};

class Truck: public Transport
{
  double loadweight;
  bool trailer;
public:
  Truck(){}
  void Fill() override { Init("DAF euro 5", 2016, "orange", 30000, 20000, false); }
  void Init(string md, int yr, string col, double pr, double load, bool tr)
  {
    Transport::Init(md,yr,col,pr);
    koleso = 6;
    loadweight = load;
    trailer = tr;
  }
  void Print() override
  {
    Transport::Print();
    cout << "Load weight: " << loadweight << "kg" << endl;
    cout << "Trailer: " << trailer << endl << endl;
  }
  void MaxSpeed() override { cout << "Max speed: 110 km/h" << endl; }
  void FuelConsumption() override { cout << "Fuel consumption: 28 l/100km" << endl; }
  void Wheels() override { cout << "Wheels: " << koleso << endl; }
  void Passengers() override { cout << "Passengers: 2 (cabin)" << endl; }
};

int main()
{
  Transport* t = nullptr;
  int choice = 0;

  cout << "1 - Bicycle" << endl;
  cout << "2 - Motorcycle" << endl;
  cout << "3 - Sedan" << endl;
  cout << "4 - Jeep" << endl;
  cout << "5 - Bus" << endl;
  cout << "6 - Truck" << endl;
  cout << "Make your choice: ";

  cin >> choice;

  switch (choice)
  {
    case 1:
      t = new Bicycle;
      break;
    case 2:
      t = new Motorcycle;
      break;
    case 3:
      t = new Sedan;
      break;
    case 4:
      t = new Jeep;
      break;
    case 5:
      t = new Bus;
      break;
    case 6:
      t = new Truck;
      break;
    default:
      cout << "Wrong choice!" << endl;
      return 1;
  }

  t->Fill();
  t->Print();
  t->MaxSpeed();
  t->FuelConsumption();
  t->Wheels();
  t->Passengers();

  delete t;

  return 0;
}