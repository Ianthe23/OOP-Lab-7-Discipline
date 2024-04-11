#ifndef TESTS_H_
#define TESTS_H_

#include "domain.h"
#include "repo.h"
#include "validator.h"
#include "service.h"
#include <assert.h>

class Tests {
	void testDomain();
	void testConstructor_Getters();
	void testCopyConstructor();
	void testSetters();
	void testToString();
	void testOperatori();
	void testComparatori();

	void testRepo();
	void testAdaugaRepo();
	void testModificaRepo();
	void testCautaRepo();
	void testStergeRepo();
	void testGet_disciplina();

	void testValidator();
	void testDynamicVector();

	void testService();
	void testAdaugaSrv();
	void testModificaSrv();
	void testStergeSrv();
	void testCautaSrv();
	void testFiltrare();
	void testSortare();


public:
	Tests() noexcept{};
	void testAll();
	~Tests() {

	};
};


#endif /* TESTS_H_ */
