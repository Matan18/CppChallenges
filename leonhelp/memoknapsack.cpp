#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> gunsAmmoArray;
vector<float> gunsDamageArray;
float memo[14][10050];
// valor * peso;

map<string, float> guns{
    pair<string, float>("HANDCANNON", 60),
    pair<string, float>("STRIKER", 12),
    pair<string, float>("RIFLE", 12),
    pair<string, float>("RED9", 3.5),
    pair<string, float>("BLACKTAIL", 3.5),
    pair<string, float>("HANDGUN", 2),
    pair<string, float>("MATILDA", 2),
    pair<string, float>("TMP", 1.2),
},
    enimies{
        pair<string, int>("GANADOS", 50),
        pair<string, int>("COBRAS", 40),
        pair<string, int>("ZEALOT", 75),
        pair<string, int>("COLMILLOS", 60),
        pair<string, int>("GARRADOR", 125),
        pair<string, int>("LASPLAGAS", 100),
        pair<string, int>("GATLINGMAN", 150),
        pair<string, int>("REGENERATOR", 250),
        pair<string, int>("ELGIGANTE", 500),
        pair<string, int>("DR.SALVADOR", 350),
    };

float gunDamage(string gunName, int gunAmount)
{
  return guns[gunName] * gunAmount;
}

int enimiesLife(string enimyName, int enimyAmount)
{
  return enimies[enimyName] * enimyAmount;
}

int knapsack(int gunsIndex, int restAmmo)
{
  if (gunsIndex < 0 || restAmmo == 0)
  {
    return 0;
  }
  if (memo[gunsIndex][restAmmo] != -1)
  {
    return memo[gunsIndex][restAmmo];
  }
  if (gunsAmmoArray[gunsIndex] > restAmmo)
  {
    return knapsack(gunsIndex - 1, restAmmo);
  }
  int temp1 = knapsack(gunsIndex - 1, restAmmo);
  int temp2 = gunsDamageArray[gunsIndex] +
              knapsack(gunsIndex - 1,
                       restAmmo - gunsAmmoArray[gunsIndex]);
  return memo[gunsIndex][restAmmo] = max(temp1, temp2);
}

int main()
{
  int gunsAmount;
  while (cin >> gunsAmount)
  {
    int enimiesTypesAmount, maxAmmo, ammoCount = 0;
    float damageResult = 0, enimiesTotalLife = 0;

    for (int i = 0; i < gunsAmount; i++)
    {
      int count;
      string gunName;
      cin >> gunName >> count;

      gunsAmmoArray.push_back(count);
      gunsDamageArray.push_back(gunDamage(gunName, count));
    }
    cin >> enimiesTypesAmount;

    for (int i = 0; i < enimiesTypesAmount; i++)
    {
      int count;
      string enimyName;
      cin >> enimyName >> count;
      enimiesTotalLife += enimiesLife(enimyName, count);
    }
    cin >> maxAmmo;

    for (int i = 0; i < gunsAmount; i++)
    {
      for (int j = 0; j <= maxAmmo; j++)
      {
        memo[i][j] = -1;
      }
    }

    int result = knapsack(gunsAmount - 1, maxAmmo);

    bool hasDamage = result >= enimiesTotalLife;
    cout << ((hasDamage) ? "Missao completada com sucesso"
                         : "You Are Dead")
         << endl
         << endl;

    gunsAmmoArray.clear();
    gunsDamageArray.clear();
  }
  return 0;
}
