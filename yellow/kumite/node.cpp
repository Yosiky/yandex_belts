#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const std::string &str) const {
	return (true); 
}

DateComparisonNode::DateComparisonNode(const Comparison &arg_cmp, 
	const Date &arg_date)
	:	cmp(arg_cmp), date(arg_date) { }

bool DateComparisonNode::Evaluate(const Date &date, const std::string &str) const {
	switch (cmp) {
	case (Comparison::Less) :
		return (std::less<Date>{}(date, this->date));
		break ;
	case (Comparison::LessOrEqual) :
		return (std::less_equal<Date>{}(date, this->date));
		break ;
	case (Comparison::Greater) :
		return (std::greater<Date>{}(date, this->date));
		break ;
	case (Comparison::GreaterOrEqual) :
		return (std::greater_equal<Date>{}(date, this->date));
		break;
	case (Comparison::Equal) :
		return (std::equal_to<Date>{}(date, this->date));
		break ;
	case (Comparison::NotEqual) :
		return (std::not_equal_to<Date>{}(date, this->date));
		break ;
	}
}

EventComparisonNode::EventComparisonNode(const Comparison &arg_cmp, 
	const std::string &arg_event)
	:	cmp(arg_cmp), event(arg_event) { }

bool EventComparisonNode::Evaluate(const Date &date, const std::string &str) const {
	switch (cmp) {
	case (Comparison::Less) :
		return (std::less<std::string>{}(str, event));
		break ;
	case (Comparison::LessOrEqual) :
		return (std::less_equal<std::string>{}(str, event));
		break ;
	case (Comparison::Greater) :
		return (std::greater<std::string>{}(str, event));
		break ;
	case (Comparison::GreaterOrEqual) :
		return (std::greater_equal<std::string>{}(str, event));
		break;
	case (Comparison::Equal) :
		return (std::equal_to<std::string>{}(str, event));
		break ;
	case (Comparison::NotEqual) :
		return (std::not_equal_to<std::string>{}(str, event));
		break ;
	}
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &arg_log_op, 
	const std::shared_ptr<Node> &arg_lft_node, 
	const std::shared_ptr<Node> &arg_rht_node) 
	:	logical_operation(arg_log_op), 
		left(arg_lft_node), 
		right(arg_rht_node) { }

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &str) const {
	switch (logical_operation) {
	case (LogicalOperation::And): 
		return (left->Evaluate(date, str) && right->Evaluate(date, str));
		break ;
	case (LogicalOperation::Or):
		return (left->Evaluate(date, str) || right->Evaluate(date, str));
		break ; 
	}
}
