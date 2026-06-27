class Box {
    private double length;
    private double breadth;

    public Box(double length, double breadth) {
        this.length  = length;
        this.breadth = breadth;
    }

    public double getLength()  { return length;  }
    public double getBreadth() { return breadth; }

    public double area() {
        return length * breadth;
    }

    public void display() {
        System.out.println("Length:  " + length);
        System.out.println("Breadth: " + breadth);
        System.out.println("Area:    " + area());
    }
}

class Box3D extends Box {
    private double height;

    public Box3D(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    public double volume() {
        return getLength() * getBreadth() * height;
    }

    public void display() {
        super.display();
        System.out.println("Height:  " + height);
        System.out.println("Volume:  " + volume());
    }

    public static void main(String[] args) {
        System.out.println("--- Box ---");
        Box b = new Box(5, 3);
        b.display();

        System.out.println("\n--- Box3D ---");
        Box3D b3 = new Box3D(5, 3, 4);
        b3.display();
    }
}