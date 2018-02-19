package dumbbell;

public final class Dumbbell {

	
	private String Type;
	private String Colour;
    private int Quantity;
    private double Price;
    private double Weight;
    
    private static double GeneralWeight = 0.0;
    
	public String getType() {
		return Type;
	}
	public void setType(String Type) {
		this.Type = Type;
	}
	
	public String getColour() {
		return Colour;
	}
	
	public void setColour(String Colour) {
		this.Colour = Colour;
	}
	
	public int getQuantity() {
		return Quantity;
	}
	
	public void setQuantity(int Quantity) {
		this.Quantity = Quantity;
	}
	
	public double getPrice() {
		return Price;
	}
	
	public void setPrice(double Price) {
		this.Price = Price;
	}
	
	public double getWeight() {
		return Weight;
	}
	
	public void setWeight(double Weight) {
	        GeneralWeight = GeneralWeight - this.Weight + Weight;
		this.Weight=Weight;
	}
	
	private Dumbbell() {
		Type = "Small dumbbell";
		Colour = "Pink";
		Quantity = 1;
		Price = 30.5;
		Weight = 2.5;
		GeneralWeight += (Weight*Quantity);
	}
	
	private Dumbbell(String Type, String Colour, int Quantity, double Price){
		setType(Type);
		setColour(Colour);
		setQuantity(Quantity);
		setPrice(Price);
		Weight = 5.0;
		GeneralWeight += (Weight*Quantity);
	}
	
	private Dumbbell(String Type, String Colour, int Quantity, double Price, double Weight){
		setType(Type);
		setColour(Colour);
		setQuantity(Quantity);
		setPrice(Price);
		setWeight(Weight);
	}
	
        @Override
     	public String toString() {
		return getColour() + " " + getType() + " in the quantity of " + getQuantity() + " weighs " + getWeight() + " kg and costs " + getPrice() + " hrn." ;
        }
	
	public static void printStaticSum() {
		System.out.println("Total dumbbells weight is " + GeneralWeight + " kg.");
	}
	
	public void printSum() {
		System.out.println("Total weight of this " + Type + "s is " + Weight + " kg.");
	}
	
	public void resetValues(String Type, String Colour, int Quantity, double Price, double Weight) {
		setType(Type);
		setColour(Colour);
		setQuantity(Quantity);
		setPrice(Price);
		setWeight(Weight);
	}

	public static void main(String[] args) {
		Dumbbell small_dumbbell = new Dumbbell();
		Dumbbell middle_dumbbell = new Dumbbell("Middle dumbbell", "Black", 6, 300.0);
		Dumbbell big_dumbbell = new Dumbbell("Big dumbbell", "Blue", 10, 55.0, 100.0);
		
		System.out.println(small_dumbbell.toString());
		System.out.println(middle_dumbbell.toString());
		System.out.println(big_dumbbell.toString());
		
		Dumbbell.printStaticSum();
		
		small_dumbbell.printSum();
		middle_dumbbell.printSum();
		big_dumbbell.printSum();
	}
}

