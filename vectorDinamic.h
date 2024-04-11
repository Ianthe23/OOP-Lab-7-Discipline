#ifndef VECTORDINAMIC_H_
#define VECTORDINAMIC_H_

#define CAPACITATE_INITIALA 2

template<typename ElemType>
class IteratorVector;

template<typename ElemType>
class VectorDinamic {
private:
    ElemType* elemente; // vectorul de elemente
    int lungime;
    int capacitate;
    void asiguramCapacitate([[maybe_unused]]int factor = 2);

public:
    // CONSTRUCTOR
    VectorDinamic();

    // DESTRUCTOR
    ~VectorDinamic();

    // VECTOR DE COPIERE
    VectorDinamic(const VectorDinamic& copie);

    /// OPERATORI
    // operator de ASIGNARE
    VectorDinamic& operator=(const VectorDinamic& vector);

    // mutam constructorul
    VectorDinamic(VectorDinamic&& vector) noexcept;

    // mutam asignarea
    VectorDinamic& operator=(VectorDinamic&& vector) noexcept;

    // adaugam in vector
    void push_back(const ElemType& element);

    // stergem
    void erase(int pozitie);

    /// GETTER element
    [[maybe_unused]] ElemType& get(int pozitie) const;

    // SETTER
    [[maybe_unused]] void set(int pozitie, const ElemType& element);

    // luam lungimea
    [[nodiscard]] int getLungime() const noexcept;

    // declaram iteratorul ca o clasa prietena
    friend class IteratorVector<ElemType>;

    // iteratorii vectorului
    IteratorVector<ElemType> begin() const;
    IteratorVector<ElemType> end() const;

    [[nodiscard]] bool empty() const noexcept;

    [[maybe_unused]] IteratorVector<ElemType> iterator() {
        return IteratorVector(*this);
    };
    ElemType& operator[](int pozitie) const;
};

// suprascrierea operatorului
template<typename ElemType>
ElemType& VectorDinamic<ElemType>::operator[](int pozitie) const {
    return elemente[pozitie];
}

// CONSTRUCTOR
template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic() : lungime(0), capacitate(CAPACITATE_INITIALA) {
    this->elemente = new ElemType[CAPACITATE_INITIALA];
}

// COPIA CONSTRUCTORULUI
template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(const VectorDinamic<ElemType>& copie) {
    this->capacitate = copie.capacitate;
    this->lungime = copie.lungime;
    this->elemente = new ElemType[capacitate];

    // Copy only up to the length of the original vector
    for (int i = 0; i < lungime; ++i) {
        elemente[i] = copie.elemente[i];
    }
}

// verificam daca e gol
template<typename ElemType>
bool VectorDinamic<ElemType>::empty() const noexcept {
    return lungime == 0;
}

// ASIGNAREA
template<typename ElemType>
VectorDinamic<ElemType>& VectorDinamic<ElemType>::operator=(const VectorDinamic<ElemType>& vector) {
    if (this == &vector) {
        return *this;
    }
    delete[] elemente;
    elemente = new ElemType[vector.capacitate];
    // copiem elementele
    for (int i = 0; i < vector.lungime; ++i) {
        elemente[i] = vector.elemente[i];
    }
    lungime = vector.lungime;
    capacitate = vector.capacitate;
    return *this;
}

// DESTRUCTOR
template<typename ElemType>
VectorDinamic<ElemType>::~VectorDinamic() {
    delete[] elemente;
    lungime = 0;
    capacitate = 0;
}

template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(VectorDinamic&& vector) noexcept {
    // copiem datele
    elemente = vector.elemente;
    lungime = vector.lungime;
    capacitate = vector.capacitate;

    // le stergem din vector
    vector.elemente = nullptr;
    vector.lungime = 0;
    vector.capacitate = 0;
}

// MUTAREA ASIGNARII
template<typename ElemType>
VectorDinamic<ElemType>& VectorDinamic<ElemType>::operator=(VectorDinamic<ElemType>&& vector) noexcept {
    if (this == &vector) {
        return *this;
    }

    delete[] elemente;
    // copiem datele de la vector in this
    elemente = vector.elemente;
    lungime = vector.lungime;
    capacitate = vector.capacitate;

    // stergem datele de la vector pt ca le-am mutat
    vector.elemente = nullptr;
    vector.lungime = 0;
    vector.capacitate = 0;

    return *this;
}

template<typename ElemType>
void VectorDinamic<ElemType>::erase(int pozitie) {
    this->lungime--;
    for (int i = pozitie; i < this->lungime; ++i) {
        this->elemente[i] = this->elemente[i + 1];
    }
}

template<typename ElemType>
void VectorDinamic<ElemType>::push_back(const ElemType& element) {
    asiguramCapacitate();
    elemente[lungime++] = element;
}

/// GETTER
template<typename ElemType>
[[maybe_unused]] ElemType& VectorDinamic<ElemType>::get(int pozitie) const {
    return elemente[pozitie];
}

/// SETTER
template<typename ElemType>
[[maybe_unused]] void VectorDinamic<ElemType>::set(int pozitie, const ElemType& element) {
    elemente[pozitie] = element;
}

template<typename ElemType>
int VectorDinamic<ElemType>::getLungime() const noexcept {
    return lungime;
}

template<typename ElemType>
void VectorDinamic<ElemType>::asiguramCapacitate([[maybe_unused]]int factor) {
    if (lungime < capacitate) {
        return;
    }
    capacitate *= 2;
    auto* aux = new ElemType[capacitate];
    for (int i = 0; i < lungime; ++i) {
        aux[i] = elemente[i];
    }
    delete[] elemente;
    elemente = aux;
}

template<typename ElemType>
IteratorVector<ElemType> VectorDinamic<ElemType>::begin() const {
    return IteratorVector<ElemType>(*this);
}

template<typename ElemType>
IteratorVector<ElemType> VectorDinamic<ElemType>::end() const {
    return IteratorVector<ElemType>(*this, lungime);
}

template<typename ElemType>
class IteratorVector {
private:
    const VectorDinamic<ElemType>& vector;
    int pozitie = 0;
public:
    explicit IteratorVector(const VectorDinamic<ElemType>& vector);
    IteratorVector(const VectorDinamic<ElemType>& vector, int pozitie) noexcept;

    [[maybe_unused]] [[nodiscard]] bool valid()const;
    ElemType& element() const;
    void next();
    ElemType& operator*();
    IteratorVector& operator++();

    bool operator == (const IteratorVector& ot) noexcept;
    bool operator != (const IteratorVector& ot) noexcept;
};

template<typename ElemType>
IteratorVector<ElemType>::IteratorVector(const VectorDinamic<ElemType>& vec) : vector(vec) {}

template<typename ElemType>
IteratorVector<ElemType>::IteratorVector(const VectorDinamic<ElemType>& vec, int pozitie) noexcept : vector(vec), pozitie(pozitie) {}

template<typename ElemType>
[[maybe_unused]] bool IteratorVector<ElemType>::valid() const {
    return pozitie < vector.lungime;
}

template<typename ElemType>
ElemType& IteratorVector<ElemType>::element() const {
    return vector.elemente[pozitie];
}

template<typename ElemType>
void IteratorVector<ElemType>::next() {
    pozitie++;
}

template<typename ElemType>
ElemType& IteratorVector<ElemType>::operator*() {
    return element();
}

template<typename ElemType>
IteratorVector<ElemType>& IteratorVector<ElemType>::operator++() {
    next();
    return *this;
}

template <typename ElemType>
bool IteratorVector<ElemType>:: operator==(const IteratorVector<ElemType>& ot) noexcept {
    return ot.pozitie == pozitie;
}

template <typename ElemType>
bool IteratorVector<ElemType>:: operator!=(const IteratorVector<ElemType>& ot) noexcept {
    return !(*this == ot);
}

#endif /* VECTORDINAMIC_H_ */
