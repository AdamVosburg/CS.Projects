//IT-145 Grazios Project
// Adam Vosburg
// 01/28/2023

import java.util.ArrayList;
import java.util.Scanner;

public class Driver {
    private static ArrayList<Dog> dogList = new ArrayList<Dog>();
    private static ArrayList<Monkey> monkeyList = new ArrayList<Monkey>(); //added a new array for my monkey type
    

    public static void main(String[] args) {
        initializeDogList();
        initializeMonkeyList();
		Scanner scan = new Scanner(System.in); //initializing a scanner for user input

        //This code below will print a menu requesting user input

		System.out.println("To display our menu, press 'M'.  To quit, press 'q'"); 
		String userInput = scan.nextLine();
		if (userInput.equalsIgnoreCase("M")) {
			displayMenu();
			userInput = scan.nextLine();
			while (!userInput.equalsIgnoreCase("q")) { //This loop will continue running until user inputs a 'q'
				if (userInput.equals("1")) { //allows the ability to input a new dog object
				    intakeNewDog(scan); 
				    displayMenu(); //brings the main menu back up
				    userInput = scan.nextLine();
				}
				else if (userInput.equals("2")) { //allows the input of a new monkey object
				    intakeNewMonkey(scan); 
				    displayMenu();
				    userInput = scan.nextLine();
				}
				else if (userInput.equals("3")) {
				    reserveAnimal(scan); //allows any animal to be reserved from the system
				    displayMenu();
				    userInput = scan.nextLine();
				}
				else if (userInput.equals("4")) {
				    printAnimals("Dog"); //prints list of all Grazios dogs
                    displayMenu();
				    userInput = scan.nextLine();
				}
				else if (userInput.equals("5")) {
				    printAnimals("Monkey"); //Prints list of all Grazios monkeys
                    displayMenu();
				    userInput = scan.nextLine();
				}
				else if (userInput.equals("6")) {
				    printReserved("Reserved Animals"); //Prints list of all animals available at Grazios
                    displayMenu();
				    userInput = scan.nextLine();
				}
				else {
				    System.out.println("Invalid Selection"); //will prompt the user if invalid arguments are passed
				    displayMenu();
				    userInput = scan.nextLine();
				}
			}
		} else { //Entered when user hits the 'q' input
            System.out.println("Thank you for coming to our page.  We look forward to helping you in the future!");
        }
			   
    }

    // This method prints the menu options at inception of the program:

    public static void displayMenu() {
        System.out.println("\n\n");
        System.out.println("\t\t\t\tRescue Animal System Menu");
        System.out.println("[1] Intake a new dog");
        System.out.println("[2] Intake a new monkey");
        System.out.println("[3] Reserve an animal");
        System.out.println("[4] Print a list of all dogs");
        System.out.println("[5] Print a list of all monkeys");
        System.out.println("[6] Print a list of all animals that are not reserved");
        System.out.println("[q] Quit application");
        System.out.println();
        System.out.println("Enter a menu selection");
    }


    // Adds dogs to a list for testing
    public static void initializeDogList() {
        Dog dog1 = new Dog("Spot", "German Shepherd", "male", "1", "25.6", "05-12-2019", "United States", "in service", false, "United States");
        Dog dog2 = new Dog("Rex", "Great Dane", "male", "3", "35.2", "02-03-2020", "United States", "Phase I", false, "United States");
        Dog dog3 = new Dog("Bella", "Chihuahua", "female", "4", "25.6", "12-12-2019", "Canada", "in service", false, "Canada");

        dogList.add(dog1);
        dogList.add(dog2);
        dogList.add(dog3);
    }


    // Adds monkeys to a list for testing
    
    public static void initializeMonkeyList() {
    	Monkey monkey1 = new Monkey("George", "Macaque", "18", "Male", "19", "18", "37", "24", "03-31-2022", "Venezuela", "Phase II", false, "France");
    	monkeyList.add(monkey1);
        Monkey monkey2 = new Monkey("Frida", "Capuchin", "24", "Female", "19", "15", "30", "22", "07-21-2021", "Peru", "in service", false, "Mexico");
        monkeyList.add(monkey2);
        Monkey monkey3 = new Monkey("Glenda", "Tamarin", "18", "Female", "20", "21", "24", "18", "6-30-2021", "El Salvador", "in service", false, "Mexico");
        monkeyList.add(monkey3);
    }

    // this method was completed already 

    public static void intakeNewDog(Scanner scan) {
        System.out.println("What is the dog's name?\n");
        String name = scan.nextLine();
        for(Dog dog: dogList) {
            if(dog.getName().equalsIgnoreCase(name)) {
                System.out.println("\nThis dog is already in our system\n");
                return; //returns to menu
            }
        }
        //User prompted input below

        System.out.println("Enter the dog breed: ");
        String breed = scan.nextLine();
        System.out.println("Enter the dog gender: ");
        String gender = scan.nextLine();
        System.out.println("Enter the dog age: ");
        String age = scan.nextLine();
        System.out.println("Enter the dog weight: ");
        String weight = scan.nextLine();
        System.out.println("Enter the acquisition date: ");
        String acquisitionDate = scan.nextLine();
        System.out.println("Enter the acquisition location: ");
        String acquisitionCountry = scan.nextLine();
        System.out.println("Enter the Training Status: ");
        String trainingStatus = scan.nextLine();
        System.out.println("Dog is reserved? true or false: ");
        boolean reserved = scan.nextBoolean();
        scan.nextLine();
        System.out.println("In which country is the dog in service?");
        String inServiceCountry = scan.nextLine();

        //used to update any new dog information into the system

        Dog dog4 = new Dog(name, breed, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
        dogList.add(dog4); //this adds a new new dog object into the array
        System.out.println("Your dog has been recorded into our system.\n");
            return; 
    }

        // this method begins the monkey intake process

    public static void intakeNewMonkey(Scanner scan) {
    	System.out.println("Please provide the monkey's name?");
        String name = scan.nextLine();
        for(Monkey monkey: monkeyList) { //this will check if the monkey exists in the system
            if(monkey.getName().equalsIgnoreCase(name)) {
                System.out.println("This monkey already exists in our system\n");
                return; 
            }
        }
        //Input user specs  for monkey species

        System.out.println("Please enter the monkeys' species: ");
        String species = scan.nextLine();
        if (!monkeyList.contains(species)) {
        	System.out.println("The species you have entered is invalid. Valid Monkey Species includes: Capuchin, Guenon, Macaque, Marmoset, Squirrel monkey, or Tamarin");
        	System.out.println("Enter a valid monkey species: ");
        	species = scan.nextLine();
        }
        //Inputs the rest of specs for monkey intake

        System.out.println("Enter the monkey's age: ");
        String age= scan.nextLine();
        System.out.println("Enter the monkey's gender: ");
        String gender = scan.nextLine();
        System.out.println("Enter the monkey's height: ");
        String height = scan.nextLine();
        System.out.println("Enter the monkey's weight: ");
        String weight = scan.nextLine();
        System.out.println("Enter the monkey's tail length:");
        String tailLength = scan.nextLine();
        System.out.println("Enter the monkey's body length: ");
        String bodyLength = scan.nextLine();
        System.out.println("Enter the monkeys's acquisition date: ");
        String acquisitionDate = scan.nextLine();
        System.out.println("Enter the monkey's acquisition location: ");
        String acquisitionCountry = scan.nextLine();
        System.out.println("Enter the Training Status: ");
        String trainingStatus = scan.nextLine();
        System.out.println("Is this monkey reserved? true or false: ");
        boolean reserved = scan.nextBoolean();
        scan.nextLine();
        System.out.println("In which country is the monkey in service?");
        String inServiceCountry = scan.nextLine();

		//References the monkey constructor to add a new monkey into the system

        Monkey monkey4 = new Monkey(name, species, age, gender, height, weight, tailLength, bodyLength, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry);
        monkeyList.add(monkey4); 
        System.out.println("Your monkey has been recorded into our system\n");
            return; 
    }    

        // Reserves any available dog and monkey if training status, reserved equals false and in service location matches.
        
        public static void reserveAnimal(Scanner scan) {
            System.out.println("Are you trying to reserve a Dog or a Monkey?");
            String animalType = scan.nextLine();
            System.out.println("In which country would you like to reserve the animal?");
            String inServiceCountry = scan.nextLine();
            if(animalType.equalsIgnoreCase("Monkey")) {
            	for(Monkey monkey: monkeyList) {
            		if(monkey.getInServiceLocation().equalsIgnoreCase(inServiceCountry) && monkey.getTrainingStatus().equalsIgnoreCase("in service") && monkey.getReserved() == false) {
            		monkey.setReserved(true);
            		System.out.println("You have reserved " + monkey.toString());
                    break;
                    }
            		                    
                    else{
            			System.out.println("This monkey is not available for reservation.");
            		}
            	}
            }
            else { 
            	for(Dog dog: dogList) {
            		if(dog.getInServiceLocation().equalsIgnoreCase(inServiceCountry) && dog.getTrainingStatus().equalsIgnoreCase("in service") && dog.getReserved() == false) {
            		dog.setReserved(true);
                    System.out.println("You have reserved " + dog.toString());
                    break;
            		}
                    else {
            		System.out.println("This dog is not available for reservation");
            		}
            	}
            }
            }
            // Beginning print statements that lists all animals of dog and monkey types in Grazios
        
        public static void printAnimals(String animalType) {
            if(animalType.equalsIgnoreCase("Dog")) {
            	System.out.println("Here is a list of all dogs we have at Grazios:\n");
            	for(Dog dog: dogList) {
            	System.out.println(dog.toString());
            	}
            }
            if(animalType.equalsIgnoreCase("Monkey")) {
                System.out.println("Here is a list of the all monkeys we have at Grazios:\n");
            	for(Monkey monkey: monkeyList) {
            	System.out.println(monkey.toString());
            	}
            }
        }
            // this method will check which animals are available by calling traing status and reserved boolean. 
            
        public static void printReserved(String animalType) {
            System.out.println("Here are the Dogs and Monkeys available for reservation:\n");
            System.out.println("Dogs able to be reserved\n");
            for(Dog dog: dogList) {
                if(dog.getTrainingStatus().equalsIgnoreCase("in service") && dog.getReserved()== false) {
                System.out.println(dog.toString());
                } 
                 
                  
            }
            System.out.println("Monkeys able to be reserved\n");   
            for(Monkey monkey: monkeyList) {
                if(monkey.getTrainingStatus().equalsIgnoreCase("in service") && monkey.getReserved()== false) {
                System.out.println(monkey.toString());
                } 
                  
            }
        }
    
    
}

    


