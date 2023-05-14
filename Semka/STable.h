//#pragma once
//#include "libds/adt/table.h"
//#include "UzemnaJednotka.h"
//
//template <typename K, typename T>
//struct TableItem
//{
//    K key_;
//    T data_;
//
//    bool operator==(const TableItem<K, T>& other) const
//    {
//        return key_ == other.key_ && data_ == other.data_;
//    }
//
//    bool operator!=(const TableItem<K, T>& other) const
//    {
//        return !(*this == other);
//    }
//};
//
//template <typename K, typename T>
//using TabItem = TableItem<K, T>;
//
//template <typename K, typename T>
//class STable : ds::adt::SortedSequenceTable
//{
//private:
//	bool tryFindBlockWithKey(K key, size_t firstIndex, size_t lastIndex, BlockType*& lastBlock);
//protected:
//	using BlockType = typename amt::IS<TabItem<K, T>>::BlockType;
//	BlockType* findBlockWithKey(K key) override;
//public:
//	void insert(K key, T data) override;
//	T remove(K key) override;
//};
//
