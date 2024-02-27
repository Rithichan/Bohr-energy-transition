//Assignment 1: Transition energy of Bohr Model
//Simple program that finds the transition energy of the Bohr Model
//Rithichan Chhorn, ID: 10812107, 01/02/2024

#include<iostream>
#include<cmath>
#include <iomanip>

//Defining Global Variables
const float rydberg_energy_ev{13.6};

float energy_calculation(int atomic_number, int principal_quantum_number_i, int principal_quantum_number_f)
{
  float transition_energy;

  //Calculates the transition energy in eV
  transition_energy = rydberg_energy_ev*pow(atomic_number, 2)*(pow(principal_quantum_number_f,-2)-pow(principal_quantum_number_i,-2));

  return transition_energy;

}

void input_and_calculation()
{
  //Declaring the variables
  int atomic_number;
  int principal_quantum_number_i;
  int principal_quantum_number_f;
  char energy_unit;
  float transition_energy;

  //Asking for user input
  std::cout<<"Enter the atomic number, initial quantum number, final quantum number, and the unit of energy: ";
  std::cin>>atomic_number>>principal_quantum_number_i>>principal_quantum_number_f>>energy_unit;

  //User input validation
  while(true)
  {
    bool input_valid{true};
    if(std::cin.fail())
    {
      std::cout<<"Atomic and quantum numbers needs to be an integer."<<std::endl;
      input_valid = false;
    }
    if(atomic_number < 0 || principal_quantum_number_i < 0 || principal_quantum_number_f < 0)
    {
      std::cout<<"Atomic number and quantum numbers must be greater than 0"<<std::endl;
      input_valid = false;
    }
    if(principal_quantum_number_i < principal_quantum_number_f)
    {
      std::cout<<"Initial quantum number needs to be greater than the final quantum number."<<std::endl;
      input_valid = false;
    }
    if(energy_unit != 'e' && energy_unit != 'j')
    {
      std::cout<<"Energy units are e for eV and j for Joules."<<std::endl;
      input_valid = false;
    }
    if(input_valid == true)
    {
      break;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Please try again: ";
    std::cin>>atomic_number>>principal_quantum_number_i>>principal_quantum_number_f>>energy_unit;
  }

  //Calculates the transition energy and prints it with the correct units
  if(energy_unit == 'e')
  {
    transition_energy = energy_calculation(atomic_number, principal_quantum_number_i, principal_quantum_number_f);
    std::cout<<"The transition energy is: "<<std::setprecision(3)<<transition_energy<<" eV."<<std::endl;
  }
  else
  {
  transition_energy = energy_calculation(atomic_number, principal_quantum_number_i, principal_quantum_number_f);
  transition_energy = transition_energy * 1.602176634 * pow(10,-19);
  std::cout<<"The transition energy is: "<<std::setprecision(3)<<transition_energy<<" joules."<<std::endl;
  }

}

int main()
{
  char repeat;

  //repeat the script if variable repeat is 'y'
  do
  {
    input_and_calculation();
    do
    {    
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout<<"Do you want to run this script again? (y/n): ";
      std::cin>>repeat;
    } while (repeat != 'y' && repeat != 'n'); //repeat question if input is neither 'y' or 'n'
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while(repeat == 'y');

  return 0;

}