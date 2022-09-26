#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
class Item {
	std::string name_;
	double cost_;
	double healAmount_;
	double scalingFactor_;
	int level_;
	int type_;
	//type_: 1 = Weapon
	//type_: 2 = Healing Item
	//type_: 3 = buff Item
public:

	Item(std::string _name = "") :name_(_name), level_(1), cost_(10), type_(0), healAmount_(0), scalingFactor_(1) {}
	Item(std::string _name, int _level, double _cost, int _type, double _scalingFactor) :name_(_name), level_(_level), cost_(_cost), type_(_type), healAmount_(0), scalingFactor_(_scalingFactor) {}
	Item(std::string _name, int _level, double _cost, int _type, double _healAmount, double _scalingFactor) :name_(_name), level_(_level), cost_(_cost), type_(_type), healAmount_(_healAmount), scalingFactor_(_scalingFactor) {}
	virtual ~Item() {}

	inline std::string getName() const { return name_; }
	constexpr int getLevel() const { return level_; }
	constexpr double getCost() const { return cost_; }
	constexpr int getType() const { return type_; }
	constexpr double getScaling() const { return scalingFactor_; }
	constexpr void setCost(double _cost) { cost_ = _cost; }
	constexpr void setLevel(int _level) { level_ = _level; }
	inline void setName(std::string _name) { name_ = _name; }
	constexpr double healAmount() const { return healAmount_; }

	friend bool operator== (const Item& lhs, const Item& rhs);

};

#endif