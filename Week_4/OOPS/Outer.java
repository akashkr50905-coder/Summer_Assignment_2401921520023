class Outer {
    void display() {
        System.out.println("I am outer class display");
    }

    class Inner {
        void display() {
            System.out.println("I am inner class display");
        }
    }

    public static void main(String[] args) {
        Outer outer = new Outer();
        outer.display();

        Outer.Inner inner = outer.new Inner();
        inner.display();
    }
}