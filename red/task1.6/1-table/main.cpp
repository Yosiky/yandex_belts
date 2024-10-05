#include "test_runner.h"

template <class T>
class Table {
    std::vector<std::vector<T>> table;

public:
    Table(const size_t lines, const size_t columns)
    {
        table.resize(lines);
        for (size_t i = 0; i < lines; ++i) {
            table[i].resize(columns);
        }
    }

    std::pair<size_t, size_t> Size(void) const
    {
        if (table.size() > 0) {
            return std::make_pair(table.size(), table[0].size());
        }
        return std::make_pair<size_t, size_t>(0, 0);
    }

    void Resize(size_t lines, size_t columns)
    {
        table.resize(lines);
        for (size_t i = 0; i < lines; ++i) {
            table[i].resize(columns);
        }
    }

    std::vector<T> &operator[](const size_t i)
    {
        return table[i];
    }

    const std::vector<T> &operator[](const size_t i) const
    {
        return table[i];
    }
};

void TestTable() {
    Table<int> t(1, 1);
    const Table<int> a(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}

