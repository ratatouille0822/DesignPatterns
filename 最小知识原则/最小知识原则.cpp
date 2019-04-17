#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class AbstractBuilding
{
public:
	virtual void sale() = 0;
	virtual string get_quality() = 0;
};

struct MyDelete
{
	void operator()(AbstractBuilding* building)
	{
		if (NULL != building)
		{
			delete building;
		}
	}
};


class BuildingA :public AbstractBuilding
{
public:
	BuildingA()
	{
		this->quality = "High Quality";
	}
	virtual void sale()
	{
		cout << "High quality building was sold" << endl;

	}
	virtual string get_quality()
	{
		return this->quality;
	}
public:
	string quality;
};

class BuildingB :public AbstractBuilding
{
public:
	BuildingB()
	{
		this->quality = "Medium Quality";
	}
	virtual void sale()
	{
		cout << "Medium quality building was sold" << endl;

	}
	virtual string get_quality()
	{
		return this->quality;
	}
	string quality;
};

class BuildingC :public AbstractBuilding
{
public:
	BuildingC()
	{
		this->quality = "Low Quality";
	}
	virtual void sale()
	{
		cout << "Low quality building was sold" << endl;


	}
	virtual string get_quality()
	{
		return this->quality;
	}
	string quality;
};

class Mediator
{
public:
	vector<AbstractBuilding*> v_building;
	Mediator()
	{
		AbstractBuilding* building = new BuildingA;
		v_building.push_back(building);
		building = new BuildingB;
		v_building.push_back(building);
		building = new BuildingC;
		v_building.push_back(building);
	}
	~Mediator()
	{
		for_each(v_building.begin(), v_building.end(), MyDelete());
	}
public:
	AbstractBuilding* FindMyBuilding(string quality)
	{
		for (vector<AbstractBuilding*>::iterator it = this->v_building.begin(); it != this->v_building.end(); it++)
		{
			if ((*it)->get_quality() == quality)
			{
				return *it;
			}
		}
		cout << "No matching Quality!" << endl;
		return NULL;
	}

};
void UserInterface(string quality)
{
	Mediator* mediator_instance = new Mediator;
	AbstractBuilding* building = mediator_instance->FindMyBuilding(quality);
	if (building != NULL)
		building->sale();
}
int main()
{
	while (1)
	{
		string quality;
		getline(cin,quality);
		UserInterface(quality);
	}
	return 0;
}