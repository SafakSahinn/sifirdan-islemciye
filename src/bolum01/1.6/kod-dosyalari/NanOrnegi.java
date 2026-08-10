public class NanOrnegi {
    public static void main(String[] args) {
        double x = 0.0 / 0.0;                                  // NaN uretir
        System.out.println("x = " + x);                        // "x = NaN"
        System.out.println("x == x: " + (x == x));             // false
        System.out.println("Double.isNaN(x): " + Double.isNaN(x)); // true
    }
}
