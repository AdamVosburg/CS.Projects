//IT-145 Grazios Project
// Adam Vosburg
// 01/28/2023

public class Monkey extends RescueAnimal {

    // Instance variable
    private String species;
    private String tailLength;
    private String height;
    private String bodyLength;

    // Constructor
    public Monkey(String name, String species, String age , String gender, 
    String weight, String tailLength, String height, String bodyLength, String acquisitionDate, String acquisitionCountry,
	String trainingStatus, boolean reserved, String inServiceCountry) {
        setName(name);
        setSpecies(species);
        setGender(gender);
        setAge(age);
        setWeight(weight);
        setTailLength(tailLength);
        setHeight(height);
        setBodyLength(bodyLength);
        setAcquisitionDate(acquisitionDate);
        setAcquisitionLocation(acquisitionCountry);
        setTrainingStatus(trainingStatus);
        setReserved(reserved);
        setInServiceCountry(inServiceCountry);

    }

    // Accessor Method
    public String getSpecies() {
        return species;
    }

    // Mutator Method
    public void setSpecies(String species) {
        this.species = species;
    }

    public String getTailLength() {
        return tailLength;
    }
    
    public void setTailLength(String tailLength) {
        this.tailLength = tailLength;
    }

    public String getHeight() {
        return height;
    }

    public void setHeight(String height) {
        this.height = height;
    }

    public String getBodyLength() {
        return bodyLength;
    }

    public void setBodyLength(String bodyLength) {
        this.bodyLength = bodyLength;
    }
    @Override
    public String toString() { //Override toString method
		return "[" + getName() + ", " + getSpecies() + ", " + getTailLength() + ", " + getHeight() + ", " + getBodyLength() + ", " + getGender() + ", " + getAge() + ", " + getWeight() + ", " + getAcquisitionDate() + ", " + getAcquisitionLocation() + ", " + getTrainingStatus() + ", " + getReserved() + ", " + getInServiceLocation() + "]";	
	}
	
}