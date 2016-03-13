//file name: lesson5_617_11.cpp
//last changed: 3/5/2016
//student: Shane Kirkley

//description: Defines a class Movie that allows programmer to add title, reviews, and mpaa rating of movies.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Movie
{
public:
    enum MPAA_rating {G, PG, PG13, R};
        //this should probably be private, but I can't figure out how to use it when it's stored in private.
        // I think MPAA_rating should be enum type so that if later you wanted to organize movies by rating, there would be
        // no chance of name errors (i.e r, R, pg13, PG-13, etc.)
    Movie(string name, MPAA_rating _MPAA_rating);
        // Constructor which creates Movie object with given title and MPAA rating.
    string getTitle();
        // returns title of movie.
    string getRating();
        // returns the MPAA rating of the movie.
    void addRating(int review);
        // adds one review to the movie, from 1-5.
    double getAverage();
        // returns the average of all reviews
    void giveRandomRatings(int amount);
        // assigns amount number of reviews to a movie for testing.

private:
    MPAA_rating rating;
    string title;
    int oneStar;
    int twoStar;
    int threeStar;
    int fourStar;
    int fiveStar;
    int totalReviews;
};

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    int test_amount;
    Movie mov1("Killer Klownz From Outer Space", Movie::R);
    Movie mov2("The Mummified Comfort Cat", Movie::PG13);
    Movie mov3("Magnets: How They Work", Movie::G);
    Movie mov4("Bob's Day Off", Movie::PG);

    cout << "The movies are:" << endl
        << mov1.getTitle() << ", rated " << mov1.getRating() << "." << endl
        << mov2.getTitle() << ", rated " << mov2.getRating() << "." << endl
        << mov3.getTitle() << ", rated " << mov3.getRating() << "." << endl
        << mov4.getTitle() << ", rated " << mov4.getRating() << "." << endl << endl;

    cout << "Test 1: Enter a number of random ratings to give to \"" << mov1.getTitle() << "\"..." << endl;
    cin >> test_amount;
    mov1.giveRandomRatings(test_amount);
    cout << test_amount << " random reviews added to " << mov1.getTitle() << "." << endl
            << "The average rating is " << mov1.getAverage() << "." << endl << endl;

    mov2.addRating(2);
    mov2.addRating(1);
    mov2.addRating(1);
    mov2.addRating(2);
    mov2.addRating(2);
    cout << "Test 2: \"" << mov2.getTitle() << "\" was not well received. All 5 viewers gave it 1 or 2 stars." << endl;
    cout << "Its average rating is " << mov2.getAverage() << "." << endl << endl;

    cout << "Test 3: \"" << mov3.getTitle() << "\" will receive 100,000 random reviews. Its average should be 3.0" << endl;
    mov3.giveRandomRatings(100000);
    cout << "The calculated average rating is " << mov3.getAverage() << "." << endl << endl;

    mov4.addRating(5);
    mov4.addRating(5);
    mov4.addRating(5);
    mov4.addRating(5);
    mov4.addRating(5);
    cout << "Test 4: \"" << mov4.getTitle() << "\" was very well received. All 5 viewers gave it 5 stars." << endl;
    cout << "The average rating is " << mov4.getAverage() << "." << endl << endl;

    cout << "End of Movie class test.";
}



Movie::Movie(string name, MPAA_rating _MPAA_rating)
{
    title = name;
    rating = _MPAA_rating;
    oneStar = 0;
    twoStar = 0;
    threeStar = 0;
    fourStar = 0;
    fiveStar = 0;
    totalReviews = 0;
}

string Movie::getTitle()
{
    return title;
}

string Movie::getRating()
{
    switch(rating)
    {
        case G: return "G";
        case PG: return "PG";
        case PG13: return "PG-13";
        case R: return "R";
    }
}

void Movie::addRating(int review)
{
    if (review < 1 || review > 5)
    {
        cout << "Error: " << title << " assigned user rating with invalid value. Valid rating is 1-5.";
        exit(1);
    }
    switch(review)
    {
        case 1: oneStar++; break;
        case 2: twoStar++; break;
        case 3: threeStar++; break;
        case 4: fourStar++; break;
        case 5: fiveStar++; break;
    }
    totalReviews++;
}

double Movie::getAverage()
{
    int sum = oneStar + twoStar * 2 + threeStar * 3 + fourStar * 4 + fiveStar * 5;
    double avg = static_cast<double>(sum) / totalReviews;
    return avg;
}

void Movie::giveRandomRatings(int amount)
{
    int t;
    srand(time(0));
    for (int i = 0; i < amount; i++)
    {
        t = rand() % 5 + 1;
        this -> addRating(t);
    }
}
