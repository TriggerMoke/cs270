package test;

import java.util.ArrayList;
import java.util.Scanner;

public class Car {
   String brand, year;
    public Car(String brand, String year){
        this.brand=brand;
        this.year=year;
    }

    public boolean isOld(){

        return Integer.parseInt(this.year)<2000;

    }
   

public static void main(String[] args) {
ArrayList<Car> arr = new ArrayList<Car>();

arr.add(new Car("Ford GT","2002"));
arr.add(new Car("Chevrolette Corvette","1997"));
arr.add(1,new Car("Mercedes CLK-GTR","1996"));
arr.set(0,new Car("McLaren","1992"));
arr.add(0,new Car("BMW Z8","2007"));
arr.set(1,new Car("Ferrari Enzo","2010"));

for(Car curr:arr){
   if(curr.isOld()){
      System.out.println(curr.brand);
   }
}
  

}}