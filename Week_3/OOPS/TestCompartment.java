import java.util.Random;


abstract class Compartment {
    public abstract String notice();
}

class FirstClass extends Compartment {
    @Override
    public String notice() {
        return "First Class Compartment: AC coach, premium seating, ticket required.";
    }
}

class Ladies extends Compartment {
    @Override
    public String notice() {
        return "Ladies Compartment: Reserved for women passengers only.";
    }
}

class General extends Compartment {
    @Override
    public String notice() {
        return "General Compartment: Open for all passengers, unreserved seating.";
    }
}

class Luggage extends Compartment {
    @Override
    public String notice() {
        return "Luggage Compartment: For parcels and goods only, no passengers allowed.";
    }
}


public class TestCompartment {
    public static void main(String[] args) {
        Compartment[] compartments = new Compartment[10];  
        Random rand = new Random();

        for (int i = 0; i < compartments.length; i++) {
            int type = rand.nextInt(4) + 1; 

            switch (type) {
                case 1:
                    compartments[i] = new FirstClass();
                    break;
                case 2:
                    compartments[i] = new Ladies();
                    break;
                case 3:
                    compartments[i] = new General();
                    break;
                case 4:
                    compartments[i] = new Luggage();
                    break;
            }
        }

        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Coach " + (i + 1) + ": " + compartments[i].notice());
        }
    }
}