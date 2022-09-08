
package test;

/**
 * test
 */
public class test {
public static void main(String[] args) {
    System.out.println("Munge: " + munge("aabbccddeeff"));
    System.out.println("convert: "); convert(13, 2);
   
}

public static double compute(double d, int n) {
    // base case
    if (n == 0) return 0.0;
    // compute term
    double term = d;
    // recursion call
    return term + compute(d / 10.0, n - 1);
}

public static String munge(String s) {
    if (s == null || s.length() <= 1)  // base case
        return s;
    else if (s.charAt(0) == s.charAt(1))
        return munge(s.substring(1, s.length()));
    else
        return s.charAt(0) + munge(s.substring(1, s.length()));
}

public static void convert(int number, int base) {
    int remainder = number % base;
    int quotient = number / base;
    if (quotient > 0) convert(quotient, base);
    System.out.print(remainder);
}
    
}
