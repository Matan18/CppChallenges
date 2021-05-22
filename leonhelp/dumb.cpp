#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

map<string, int> gunsIndex{
    pair<string, int>("HANDCANNON", 0),
    pair<string, int>("STRIKER", 1),
    pair<string, int>("RIFLE", 2),
    pair<string, int>("RED9", 3),
    pair<string, int>("BLACKTAIL", 4),
    pair<string, int>("HANDGUN", 5),
    pair<string, int>("MATILDA", 6),
    pair<string, int>("TMP", 7),
};
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

pair<string, pair<int, float>> getDamageLine()
{
  int count;
  string gunName;
  cin >> gunName >> count;

  float damageDealt = gunDamage(gunName, count);
  return make_pair(gunName, make_pair(count, damageDealt));
}

int getEnimyLife()
{
  int count;
  string enimyName;
  cin >> enimyName >> count;
  return enimiesLife(enimyName, count);
}

pair<int, float> spendingAmmo(pair<int, float> gunWeaponed, int maxAmmo)
{
  if (gunWeaponed.first <= maxAmmo)
  {
    return make_pair(gunWeaponed.first, gunWeaponed.second);
  }
  return make_pair(0, 0);
}

int main()
{
  int gunsAmount;
  while (cin >> gunsAmount)
  {
    int enimiesTypesAmount, maxAmmo, ammoCount = 0;
    float damageResult = 0, enimiesTotalLife = 0;
    pair<int, float> gunsLoaded[8];

    for (int i = 0; i < gunsAmount; i++)
    {
      pair<string, pair<int, float>> gunResult = getDamageLine();
      gunsLoaded[gunsIndex[gunResult.first]] = gunResult.second;
      damageResult += gunResult.second.second;
    }
    cin >> enimiesTypesAmount;

    for (int i = 0; i < enimiesTypesAmount; i++)
    {
      enimiesTotalLife += getEnimyLife();
    }
    cin >> maxAmmo;

    for (int i = 0; i < 8; i++)
    {
      pair<int, float> result = spendingAmmo(gunsLoaded[i], maxAmmo);
      maxAmmo -= result.first;
      enimiesTotalLife -= result.second;
    }

    bool hasDamage = enimiesTotalLife < 0;
    bool hasAmmo = maxAmmo >= 0;
    cout << ((hasDamage && hasAmmo) ? "Missao completada com sucesso"
                                    : "You Are Dead")
         << endl
         << endl;
  }
  return 0;
}
