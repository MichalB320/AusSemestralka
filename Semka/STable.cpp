//#include "STable.h"
//
//template<typename K, typename T>
//void STable<K, T>::insert(K key, T data)
//{
//    TabItem<K, T>* tableItem;
//
//    if (this->isEmpty())
//    {
//        tableItem = &this->getSequence()->insertFirst().data_;
//    }
//    else
//    {
//        BlockType* block = nullptr;
//        if (this->tryFindBlockWithKey(key, 0, this->size(), block))
//        {
//            throw std::logic_error("Duplicate key!");
//        }
//        tableItem = key > block->data_.key_
//            ? &this->getSequence()->insertAfter(*block).data_
//            : &this->getSequence()->insertBefore(*block).data_;
//    }
//
//    tableItem->key_ = key;
//    tableItem->data_ = data;
//}
//
//template<typename K, typename T>
//T STable<K, T>::remove(K key)
//{
//    BlockType* blockWithKey = nullptr;
//    if (!this->tryFindBlockWithKey(key, 0, this->size(), blockWithKey))
//    {
//        throw std::out_of_range("No such key!");
//    }
//
//    T result = blockWithKey->data_.data_;
//    if (this->getSequence()->accessFirst() == blockWithKey)
//    {
//        this->getSequence()->removeFirst();
//    }
//    else
//    {
//        this->getSequence()->removeNext(*this->getSequence()->accessPrevious(*blockWithKey));
//    }
//    return result;
//}
//
//template<typename K, typename T>
//auto STable<K, T>::findBlockWithKey(K key) -> BlockType*
//{
//    BlockType* blockWithKey = nullptr;
//    return this->tryFindBlockWithKey(key, 0, this->size(), blockWithKey)
//        ? blockWithKey
//        : nullptr;
//}
//
//template<typename K, typename T>
//bool STable<K, T>::tryFindBlockWithKey(K key, size_t firstIndex, size_t lastIndex, BlockType*& lastBlock)
//{
//    if (this->isEmpty())
//    {
//        lastBlock = nullptr;
//        return false;
//    }
//
//    size_t midIndex = firstIndex;
//    while (firstIndex < lastIndex)
//    {
//        midIndex = firstIndex + (lastIndex - firstIndex) / 2;
//        lastBlock = this->getSequence()->access(midIndex);
//
//        if (lastBlock->data_.key_ < key)
//        {
//            firstIndex = midIndex + 1;
//        }
//        else if (lastBlock->data_.key_ > key)
//        {
//            lastIndex = mid
//        else
//        {
//            // Key found
//            return true;
//        }
//        }
//
//        lastBlock = this->getSequence()->access(midIndex);
//        return lastBlock->data_.key_ == key;
//    }
//}
