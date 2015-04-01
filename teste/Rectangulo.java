public class Rectangulo {

    class Point {

        private double x;
        private double y;

        public Point(){
            this.x = 0; 
            this.y = 0; 
        }

        public Point(Point p){
            this.x = p.getX();
            this.y = p.getY();
        }

        public Point(double x, double y){
            this.x = x;
            this.y = y;
        }

        public double distanceTo(Point p){
            return Math.sqrt(Math.pow(this.x - p.getX(), 2) + Math.pow(this.y - p.getY(), 2)); // Fórmula da distância
        }

        public void move(double dx, double dy){
            this.x += dx;
            this.y += dy;
        }

        public double getX(){
            return this.x;
        }
        public double getY(){
            return this.y;
        }
        public void setX(double x) {
            this.x = x;
        }
        public void setY(double y) {
            this.y = y;
        }

        public Point clone(){
            return new Point(x, y);
        }

        public String toString(){
            return "(" + this.x + ", " + this.y + ")"; // A representação de um ponto é: "(x, y)"
        }

        public boolean equals(Object o) {
            if (this == o){ // Se a referência é a mesma, as instâncias são a mesmo
                return true;
            }
            /* 
Se as classes forem diferentes, então as instâncias são diferentes
Se o "o" for null também é diferente, porque tudo é diferente de null em Java.
            */
            if ((o == null) || (this.getClass() != o.getClass())){ 
                return false;	
            }
            Point point = (Point) o;
            
            return point.getX() == this.x && point.getY() == this.y; 
        }

        public int hashCode(){
/* Retirado do wikipedia: http://en.wikipedia.org/wiki/Java_hashCode()

In the Java programming language, every class implicitly or explicitly provides a hashCode() method, which digests the data stored in an instance of the class into a single hash value (a 32-bit signed integer). 
This hash is used by other code when storing or manipulating the instance  the values are intended to be evenly distributed for varied inputs in order to use in clustering. 
This property is important to the performance of hash tables and other data structures that store objects in groups ("buckets") based on their computed hash values. 
Technically, in Java, hashCode() by default is a native method, meaning, it has the modifier 'native', as it is implemented directly in the native code in the JVM.
*/
            int hash = 7;
            hash = hash * 31 + Double.hashCode(this.x);
            hash = hash * 31 + Double.hashCode(this.y);
            return hash;
        }
        

    }

    private Point p1;
    private Point p2;
    private Point p3;
    private Point p4;

    /**
     * Construtor por defeito. 
     * 
     * @author Célia Figueiredo
     * @version 2014.03.11  
     *
     */
    Rectangulo(){
        this.p1 = new Point(); this.p2 = new Point(); 
        this.p3 = new Point(); this.p4 = new Point();
    }

    /**
     * Construtor de cópia.
     * 
     * @author Xavier Francisco
     * @version 2014.03.10 
     *
     */
    Rectangulo(Rectangulo r){
        this.p1 = r.getP1(); this.p2 = r.getP2(); 
        this.p3 = r.getP3(); this.p4 = r.getP4();
    }

    /**
     * Construtor parametrizado (Recebe as coordenadas dos pontos).
     * 
     * @author Tiago Cunha
     * @version 2014.03.12  
     *
     */
    Rectangulo(double x1, double y1, double x2, double y2) {
        this.p1 = new Point(x1, y1); this.p2 = new Point(x2, y1); 
        this.p3 = new Point(x1, y2); this.p4 = new Point(x2, y2); 
    }

    /**
     * Construtor parametrizado (Recebe instâncias de Pontos).
     * 
     * @author Célia Figueiredo
     * @version 2014.03.12  
     *
     */
    Rectangulo(Point p1, Point p4) {
        this.p1 = p1;                              this.p2 = new Point(p4.getX(), p1.getY()); 
        this.p3 = new Point(p1.getX(), p4.getY()); this.p4 = p4;
    }

    public double baseLength(){
        return p1.distanceTo(p2);
    }
    public double diagonalLength(){
        return p1.distanceTo(p4);
    }
    public double verticalLength(){
        return p1.distanceTo(p3);
    }

    public double area(){
        return verticalLength()*baseLength();
    }
    public double perimeter(){
        return 2*(verticalLength()+baseLength());
    }

    public void move(double dx, double dy){
        this.p1.move(dx, dy);
        this.p2.move(dx, dy);
        this.p3.move(dx, dy);
        this.p4.move(dx, dy);
    }

    public Rectangulo clone(){
        return new Rectangulo(p1.clone(), p4.clone());
    }

    public String toString(){
        return p1.toString() + p4.toString();
    }

    public boolean equals(Object o) {
        if (this == o){
            return true;
        }
        if ((o == null) || (this.getClass() != o.getClass())){
            return false;	
        }
        Rectangulo r = (Rectangulo) o;
        
        return this.p1.equals(r.getP1()) && 
               this.p2.equals(r.getP2()) &&
               this.p3.equals(r.getP3()) &&
               this.p4.equals(r.getP4());
    }

    public int hashCode(){
        int hash = 7;
        hash = hash * 31 + p1.hashCode();
        hash = hash * 31 + p2.hashCode();
        hash = hash * 31 + p3.hashCode();
        hash = hash * 31 + p4.hashCode();
        return hash;
    }
    

    public Point getP1() {
        return p1.clone();
    }
    public Point getP2() {
        return p2.clone();
    }
    public Point getP3() {
        return p3.clone();
    }
    public Point getP4() {
        return p4.clone();
    }

    public void setP1(Point p1) {
        this.p1 = p1;
    }
    public void setP2(Point p2) {
        this.p2 = p2;
    }
    public void setP3(Point p3) {
        this.p3 = p3;
    }
    public void setP4(Point p4) {
        this.p4 = p4;
    }

}

