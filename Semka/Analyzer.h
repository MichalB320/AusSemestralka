#pragma once

#include <complexities/complexity_analyzer.h>
#include <random>
#include <libds/adt/table.h>
#include <vector>

namespace ds::utils
{
	template<class Table>
	class TableAnalyzer : public ComplexityAnalyzer<Table>
	{
	protected:
		explicit TableAnalyzer(const std::string& name);
		void beforeOperation(Table& structure) override;
		void insertNElements(Table& table, size_t n);

		std::default_random_engine rngKey_;
		std::default_random_engine rngIndex_;
		std::vector<int> keys;
		int key;
		int index;
	};

	template<class Table>
	class TableInsertAnalyzer : public TableAnalyzer<Table>
	{
	public:
		explicit TableInsertAnalyzer(const std::string& name);


	protected:
		void beforeOperation(Table& structure) override;
		void executeOperation(Table& structure) override;
	};

	template<class Table>
	class TableFindAnalyzer : public TableAnalyzer<Table>
	{
	public:
		explicit TableFindAnalyzer(const std::string& name);

	protected:
		void beforeOperation(Table& structure) override;
		void executeOperation(Table& structure) override;
	};

	/**
	 * @brief Container for all Table analyzers.
	 */
	class TablesAnalyzer : public CompositeAnalyzer
	{
	public:
		TablesAnalyzer() :
			CompositeAnalyzer("Tables")
		{
			this->addAnalyzer(std::make_unique<TableInsertAnalyzer<ds::adt::SortedSequenceTable<int, int>>>("table-insert"));
			this->addAnalyzer(std::make_unique<TableFindAnalyzer<ds::adt::SortedSequenceTable<int, int>>>("table-find"));
		}
	};

	template<class Table>
	TableAnalyzer<Table>::TableAnalyzer(const std::string& name) :
		ComplexityAnalyzer<Table>(name, [this](Table& table, size_t n)
			{
				this->insertNElements(table, n);
			}),
		rngKey_(INT_MAX),
				rngIndex_(144)
	{
	}

			template<class Table>
			void TableAnalyzer<Table>::beforeOperation(Table& structure)
			{
				std::uniform_int_distribution<size_t> indexDist(0, structure.size() - 1);
			}

			template<class Table>
			void TableAnalyzer<Table>::insertNElements(Table& table, size_t n)
			{
				for (size_t i = 0; i < n; ++i)
				{
					bool notUnique = true;
					int newKey;
					while (notUnique)
					{
						newKey = rngKey_();
						if (std::count(keys.begin(), keys.end(), newKey))
							notUnique = true;
						else notUnique = false;
					}
					keys.push_back(newKey);
					table.insert(newKey, 0);
				}
			}

			template <class Table>
			TableInsertAnalyzer<Table>::TableInsertAnalyzer(const std::string& name) :
				TableAnalyzer<Table>(name)
			{
			}

			template <class Table>
			void TableInsertAnalyzer<Table>::executeOperation(Table& structure)
			{
				structure.insert(this->key, 0);
			}

			template <class Table>
			void TableInsertAnalyzer<Table>::beforeOperation(Table& structure)
			{
				bool notUnique = true;
				int newKey;
				while (notUnique)
				{
					newKey = this->rngKey_();
					if (std::count(this->keys.begin(), this->keys.end(), newKey))
						notUnique = true;
					else notUnique = false;
				}
				this->keys.push_back(newKey);
				this->key = newKey;
			}

			template <class Table>
			TableFindAnalyzer<Table>::TableFindAnalyzer(const std::string& name) :
				TableAnalyzer<Table>(name)
			{}

			template <class Table>
			void TableFindAnalyzer<Table>::executeOperation(Table& structure)
			{
				int* data = 0;
				structure.tryFind(this->keys[this->index], data);
			}

			template <class Table>
			void TableFindAnalyzer<Table>::beforeOperation(Table& structure)
			{
				std::uniform_int_distribution<size_t> indexDist(0, structure.size() - 1);
				this->index = indexDist(this->rngIndex_);
			}
}
