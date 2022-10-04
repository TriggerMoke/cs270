import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

public class StatePopulations {

    public static ArrayList<StatePair<Integer, String>> fillArray1(ArrayList<StatePair<Integer, String>> statePairs,
            Scanner inFS) {
        StatePair<Integer, String> pair;
        int intValue;
        String stringValue;

        while (inFS.hasNextLine()) {
            intValue = inFS.nextInt();
            stringValue = inFS.next();
            pair = new StatePair<Integer, String>(intValue, stringValue);
            statePairs.add(pair);
        }

        return statePairs;
    }

    public static ArrayList<StatePair<String, String>> fillArray2(ArrayList<StatePair<String, String>> statePairs,
            Scanner inFS) {
        StatePair<String, String> pair;
        String stringValue1;
        String stringValue2;

        while (inFS.hasNextLine()) {
            stringValue1 = inFS.next();
            inFS.nextLine();
            stringValue2 = inFS.nextLine();
            pair = new StatePair<String, String>(stringValue1, stringValue2);
            statePairs.add(pair);
        }

        return statePairs;
    }

    public static ArrayList<StatePair<String, Integer>> fillArray3(ArrayList<StatePair<String, Integer>> statePairs,
            Scanner inFS) {
        StatePair<String, Integer> pair;
        String stringValue;
        int intValue;

        while (inFS.hasNextLine()) {
            stringValue = inFS.nextLine();
            intValue = inFS.nextInt();
            if (inFS.hasNextLine())
                inFS.nextLine();
            pair = new StatePair<String, Integer>(stringValue, intValue);
            statePairs.add(pair);
        }

        return statePairs;
    }

    public static void main(String[] args) throws IOException {
        Scanner scnr = new Scanner(System.in);
        FileInputStream fileByteStream = null;
        Scanner inFS = null;
        int myZipCode;
        int i;

        
        ArrayList<StatePair<Integer, String>> zipCodeState = new ArrayList<StatePair<Integer, String>>();

        ArrayList<StatePair<String, String>> abbrevState = new ArrayList<StatePair<String, String>>();

        ArrayList<StatePair<String, Integer>> statePopulation = new ArrayList<StatePair<String, Integer>>();


        fileByteStream = new FileInputStream("zip_code_state.txt");
        inFS = new Scanner(fileByteStream);
        zipCodeState = fillArray1(zipCodeState, inFS);
        fileByteStream.close(); 

        // Try to open abbreviation_state.txt file
        fileByteStream = new FileInputStream("abbreviation_state.txt");
        inFS = new Scanner(fileByteStream);
        abbrevState = fillArray2(abbrevState, inFS);
        fileByteStream.close(); 

        // Try to open state_population.txt file
        fileByteStream = new FileInputStream("state_population.txt");
        inFS = new Scanner(fileByteStream);
        statePopulation = fillArray3(statePopulation, inFS);
        fileByteStream.close();

        System.out.print("Enter the zip code : ");
        myZipCode = scnr.nextInt();
        String stateAbbre = null;
        String stateName = null;

        boolean found = false;
        for (i = 0; i < zipCodeState.size(); ++i) {

            if (zipCodeState.get(i).getValue1() == myZipCode) {
                stateAbbre = zipCodeState.get(i).getValue2();
                break;
            }
        }

        if (stateAbbre != null) {
            for (i = 0; i < abbrevState.size(); ++i) {

                if (abbrevState.get(i).getValue1().equalsIgnoreCase(stateAbbre)) {
                    stateName = abbrevState.get(i).getValue2();
                    break;
                }
            }

            if (stateName != null) {
                for (i = 0; i < statePopulation.size(); ++i) {

                    if (statePopulation.get(i).getValue1().equalsIgnoreCase(stateName)) {
                        statePopulation.get(i).printInfo();
                        found = true;
                        break;
                    }
                }

            }
        }

        if (!found)
            System.out.println("Zipcode : " + myZipCode + " not found");
        scnr.close();
    }

}