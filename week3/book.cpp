#include <iostream>
#include <string>

class Book
{
  private:
    std::string bookName;
    int bookPrice;

  public:
    Book() {

    }

    Book(std::string str, int price) {
      bookName = str;
      bookPrice = price;
    }

    Book(std::string str) {
      bookName = str;
    }

    int getPrice() {
      return bookPrice;
    }

    void setPrice(int i) {
      bookPrice = i;
    }

    std::string getTitle() {
      return bookName;
    }

    void setTitle(std::string str) {
      bookName = str;
    }
};

int main(int argc, const char *argv[])
{
  //Book myfavorite = Book("Die Stadt der Traumenden Bucher", 99999);
  Book myfavorite;
  myfavorite.setTitle("Die Stadt der Tarumenden Bucher");
  myfavorite.setPrice(999999);

  std::cout << myfavorite.getTitle() << std::endl;
  std::cout << myfavorite.getPrice() << std::endl;
  return 0;
}
