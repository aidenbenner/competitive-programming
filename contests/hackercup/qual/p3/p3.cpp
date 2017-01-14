#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

struct Spell 
{
  int rolls;
  int side; 
  int offset;
};


static double eps = 0.00000001; 
double calc_prob(int health, int rolls, int side, int offset)
{
  //try calculating average roll 


  long max_possible = rolls * side + offset; 
  long min_possible = 1 * rolls + offset; //roll 1 everytime 
  
  if(health > max_possible){
    return 0;
  }
  if(health <= min_possible){
    return 1;
  }

  long diff = max_possible - min_possible; 
  long total = pow(side,rolls);  

  long poss = 0; 
  for(int i = min_possible; i<health;i++)
  {
    if(i - min_possible > diff / 2){
      poss += (diff) - (1 + i - min_possible);
    }
    else{
      poss += 1 +  i - min_possible; 
    }

  }

  cout << poss << endl << total; 
  return 1 -  (double)poss / (doubl)total; 



  /**
  double prob_side = 1.0/side; 
  if(rolls <= 0){
    return 0; 
  }
  //need to memo 
  double winning_prob = 0; 
  for(int i = 1; i<=side; i++)
  {
    int dmg = i + offset; 

    if(dmg >= health)
    {
      winning_prob += prob_side; 
    }
    else{
      winning_prob += prob_side * calc_prob(health - dmg, rolls - 1, side, offset); 
    }
    printf("%d %d %d %d %d %lf\n", i,health,rolls,side,offset,winning_prob);
  }
  return winning_prob; **/ 
}

int main()
{
  int T; 
  cin >> T; 
  for(int z = 0; z<T; z++)
  {
    //min damage
    int H;
    //spells
    int S; 
    cin >> H >> S; 


    vector<Spell> spells; 
    for(int i = 0; i<S; i++)
    {
      Spell sp; 
      cin >> sp.rolls; 
      char c; 
      cin >> c; 
      cin >> sp.side; 

      if(cin.peek() == '+' || cin.peek() == '-'){
        bool neg = cin.peek() == '-'; 
        cin >> c; 
        cin >> sp.offset; 
        if(neg){
          sp.offset *= -1; 
        }
      }
      else{
        sp.offset = 0; 
      }

      cout << endl << "read spell " << sp.rolls << " " << sp.side << " " << sp.offset; 

      spells.push_back(sp); 
    }

    double smax = 0; 
    for(int i = 0; i<spells.size(); i++)
    {
      double curr = calc_prob(H, spells[i].rolls, spells[i].side, spells[i].offset); 
      cout << endl << i << "th spell prob is " << curr << endl;
      if(curr > smax)
      {
        smax = curr; 
      }
    }

    cout << "Case #" << (z+1) << ": "; 
    printf("%.6lf\n", smax);
  }
}
