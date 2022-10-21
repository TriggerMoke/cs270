public class StatePair<Type1 extends Comparable<Type1>, Type2 extends Comparable<Type2>> {

    private Type1 value1;
    private Type2 value2;

    public StatePair() {
        value1 = (Type1) null;
        value2 = (Type2) null;
    }

    public StatePair(Type1 data1, Type2 data2) {
        value1 = data1;
        value2 = data2;
    }

    public void setValue1(Type1 data1) {
        value1 = data1;
    }

    public void setValue2(Type2 data2) {
        value2 = data2;
    }

    
    public Type1 getValue1() {
        return value1;
    }

    public Type2 getValue2() {
        return value2;
    }

    
    public void printInfo() {
        System.out.println(value1 + " : " + value2);
    }
}