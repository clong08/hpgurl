/**
 * 
 */
/**
 * @author clong
 *
 */
package monitoring;
package zoomonitoringsystem;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.IOException;

public class zoomonitoringsystem {

    private static String animalLine;
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        Scanner scnr = new Scanner(System.in);
        
        int userInput = 0;
        int detailsInput = 0;
        int i = 0;
        String habitatLine = "";
        boolean detailsFound = false;
        Scanner animalDetails = null;
        FileInputStream zooFile = null;
        Scanner habitatDetails = null;
        Scanner animalSubDetails = null;
        Scanner habitatSubDetails = null;
        
        OUTER:
        while (userInput != 3) {
            System.out.println("Would you like to monitor a animal, habitat, or exit?");
            System.out.println("1. Animal ");
            System.out.println("2. Habitat ");
            System.out.println("3. Exit ");
            System.out.println("Enter your choice: ");
            userInput = scnr.nextInt();
            System.out.println();
            switch(userInput) {
                case 1:
                    zooFile = new FileInputStream("animals.txt");
                    animalDetails = new Scanner(zooFile);
                    System.out.println("Which animal would you like to view?");
                    i = 0;
                    while (animalDetails.hasNextLine()){
                        animalLine = animalDetails.nextLine();
                        if(animalLine.contains("Details")){
                            i++;
                            System.out.println(i + ". " + animalLine);
                        }
                    }   zooFile.close();
                    System.out.print("Enter your selection: ");
                    detailsInput = scnr.nextInt();
                    System.out.println();
                    zooFile = new FileInputStream("animals.txt");
                    animalSubDetails = new Scanner(zooFile);
                    i = 0;
                    while (animalSubDetails.hasNextLine()){
                        animalLine = animalSubDetails.nextLine();
                        if(animalLine.contains("Animal")){
                           i++;
                        }
                        if (i == detailsInput){
                            detailsFound = true;
                            if(habitatLine.contains("*****")){
                                String alert = animalLine.substring(5, animalLine.length());
                                int len = alert.length()+12;
                                for (int j = 0; j < len; j++){
                                    System.out.print("!");
                                }
                                System.out.println();
                                System.out.println("! WARNING " + alert + " !");
                                for (int j = 0; j < len; j++){
                                    System.out.print("!");
                                }
                                System.out.println();
                            }
                            else if(!animalLine.isEmpty()){
                                System.out.println(animalLine);
                            }
                        }
                    }   if(detailsFound == false){
                        System.out.println("INCORRECT ENTRY!");
                    }   zooFile.close();
                    System.out.println();
                    break;
                case 2:
                    zooFile = new FileInputStream("habitats.txt");
                    habitatDetails = new Scanner(zooFile);
                    System.out.println("Which habitat would you like to monitor?");
                    i = 0;
                    while (habitatDetails.hasNextLine()){
                        habitatLine = habitatDetails.nextLine();
                        if(habitatLine.contains("Details")){
                            i++;
                            System.out.println(i + ". " + habitatLine);
                        }
                        
                    }   zooFile.close();
                    System.out.print("Enter your selection: ");
                    detailsInput = scnr.nextInt();
                    System.out.println();
                    zooFile = new FileInputStream("habitats.txt");
                    habitatSubDetails = new Scanner(zooFile);
                    i = 0;
                    while (habitatSubDetails.hasNextLine()){
                        habitatLine = habitatSubDetails.nextLine();
                        if(habitatLine.contains("Habitat")){
                            i++;
                        }
                        if (i == detailsInput){
                            detailsFound = true;
                            if(habitatLine.contains("*****")){
                                String alert = habitatLine.substring(5, habitatLine.length());
                                int len = alert.length()+12;
                                for(int j = 0; j < len; j++){
                                    System.out.print("!");
                                }
                                System.out.println();
                                System.out.println("! WARNING " + alert + " !");
                                for (int j = 0; j < len; j++){
                                    System.out.print("!");
                                }
                                System.out.println();
                            }
                            else if(!habitatLine.isEmpty()){
                                System.out.println(habitatLine);
                            }
                        }
                    }   if(detailsFound == false){
                        System.out.println("INCORRECT ENTRY!");
                    }   zooFile.close();
                    System.out.println();
                    break;
                case 3:
                    break OUTER;
                default:
                    System.out.println("INCORRECT ENTRY!");
                    System.out.println();
                    break;
            }
        }
        return;
    }
}

                    
                    
                            
                            

