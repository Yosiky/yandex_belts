#ifndef NODE_H
# define NODE_H

# include <functional>
# include <memory>
# include "date.h"

enum Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum LogicalOperation {
	And,
	Or
};

class Node {

public:

	virtual ~Node(void);

	virtual bool Evaluate(const Date &date, const std::string &str) const = 0;

};

class EmptyNode : public Node { 
public:

	~EmptyNode(void) { }

	bool Evaluate(const Date &date, const std::string &str) const;

};

class DateComparisonNode : public Node{

	Comparison cmp;
	Date date;

public:

	DateComparisonNode(const Comparison &arg_cmp, const Date &arg_date);
	~DateComparisonNode(void) { }

	bool Evaluate(const Date &date, const std::string &str) const override;
}; 

class EventComparisonNode : public Node {

	Comparison cmp;
	std::string	event;

public:

	EventComparisonNode(const Comparison &arg_cmp, const std::string &arg_event);
	~EventComparisonNode(void) { }

	bool Evaluate(const Date &date, const std::string &str) const override;

}; 

class LogicalOperationNode : public Node { 

	LogicalOperation logical_operation;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;

public:

	LogicalOperationNode(const LogicalOperation &arg_log_op, 
		const std::shared_ptr<Node> &arg_lft_node,
		const std::shared_ptr<Node> &arg_rht_node);
	~LogicalOperationNode(void) { }

	bool Evaluate(const Date &date, const std::string &str) const override;

};

#endif
