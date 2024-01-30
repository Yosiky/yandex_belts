#include <iostream>
#include <map>

#define PRINT_VAL(val) std::cout << __LINE__ << " " #val " : " << val << std::endl

using namespace std;

// enum class TaskStatus {
//   NEW,          // новая
//   IN_PROGRESS,  // в разработке
//   TESTING,      // на тестировании
//   DONE          // завершена
// };

// using TasksInfo = map<TaskStatus, int>;

class TeamTasks {

	std::map<std::string, TasksInfo> m;

public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return (m.at(person));
	}
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
		++m[person][TaskStatus::NEW];
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
		TasksInfo update;
		TasksInfo stand;
		int increase = 0;
		int last_increase = 0;

		m[person][TaskStatus::NEW];
		m[person][TaskStatus::IN_PROGRESS];
		m[person][TaskStatus::TESTING];
		m[person][TaskStatus::DONE];
		for (auto &[key, value] : m[person]) {
			if (key == TaskStatus::DONE) {
				if (last_increase) {
					update[key] = last_increase;
					value += last_increase;
				}
				break ; 
			}
			if (task_count == 0) {
				stand[key] = value;
				if (last_increase) {
					update[key] = last_increase;
					value += last_increase;
					last_increase = 0;
				}
			} else {
				if (value < task_count)
					increase = value;
				else
					increase = task_count;
				task_count -= increase;
				value -= increase;
				if (task_count == 0 && value != 0)
					stand[key] = value;
				if (increase != 0)
					update[static_cast<TaskStatus>(static_cast<int>(key) + 1)] = increase;
				value += last_increase;
				last_increase = increase;
			}
		}
		return (tie(update, stand));
	}
};

// // Принимаем словарь по значению, чтобы иметь возможность
// // обращаться к отсутствующим ключам с помощью [] и получать 0,
// // не меняя при этом исходный словарь
// void PrintTasksInfo(TasksInfo tasks_info) {
//   cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//       ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//       ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//       ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
// }

// int main() {
//   TeamTasks tasks;
//   tasks.AddNewTask("Ilia");
//   for (int i = 0; i < 3; ++i) {
//     tasks.AddNewTask("Ivan");
//   }
//   cout << "Ilia's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//   cout << "Ivan's tasks: ";
//   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//   
//   TasksInfo updated_tasks, untouched_tasks;
//   
//   tie(updated_tasks, untouched_tasks) =
//       tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);
//   
//   tie(updated_tasks, untouched_tasks) =
//       tasks.PerformPersonTasks("Ivan", 2);
//   cout << "Updated Ivan's tasks: ";
//   PrintTasksInfo(updated_tasks);
//   cout << "Untouched Ivan's tasks: ";
//   PrintTasksInfo(untouched_tasks);

//   return 0;
// }
