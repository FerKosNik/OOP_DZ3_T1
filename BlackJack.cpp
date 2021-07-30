#include <iostream>
#include <vector>
using namespace std;


class Card 
{
public:
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	enum rank {	ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING };
	
	void flip() {
		m_isFaceUp = !(m_isFaceUp);
	}

    int GetValue() const
    {
        
        int value = 0;
        if (m_isFaceUp)
        {
            
            value = m_Rank;
            
            if (value > 10) { value = 10;}
        }
        return value;
    }

private:
    rank m_Rank;
    suit m_Suit;
    bool m_isFaceUp;
};

class Hand
{
public:
    Hand();
    
    virtual ~Hand();

    void Add(Card* pCard);

    void Clear();

    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete* iter;
        *iter = 0;
    }
    
    m_Cards.clear();
}


int main()
{

	return 0;
}

