class Item {
  public String title;
  public double price;
  private int inStockQuantity;
  public double SalePrice() {return (price * 0.9);}
  public boolean isAvailable(){
    if (inStockQuantity >0 ) return true;
    else return false;
  }

  public static void main (String[] args) {
    Item A = new Item();
    A.title = "comp";
    A.price = 1000;
    System.out.println(A.SalePrice());
    System.out.println(A.title);
  }
}
