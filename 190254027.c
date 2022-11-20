/*NAME : MUHTEBER AYDIN ,NUMBER : 190254027 ,COURSE : COM 201_HW_1  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HOSPITAL_LIST_SIZE 26
#define RECORDS_ITEM_LENGTH 50

typedef struct HospitalList {
	char firstLetter;
	struct Patient *firstRecord;
} HospitalList;

typedef struct Patient {
	char name[RECORDS_ITEM_LENGTH];
	char surname[RECORDS_ITEM_LENGTH];
	int personId;
	char polyclinic[RECORDS_ITEM_LENGTH];
	struct Patient *next;
} Patient;

void printOnePatient(Patient patient) {
	printf("\n%30s %30s %20s %30s", "Name", "Surname", "Person Id",
			"Polyclinic");
	printf(
			"\n-----------------------------------------------------------------------------------------------------------------");
	printf("\n%30s %30s %20d %30s", patient.name, patient.surname,
			patient.personId, patient.polyclinic);
}

void printPatient(Patient *patient, char list) {
	printf("\n%4c %30s %30s %20d %30s", list, patient->name, patient->surname,
			patient->personId, patient->polyclinic);
}

void printPatients(Patient *head, char list) {
	while (head != NULL) {
		printPatient(head, list);
		head = head->next;
	}
}

int findPatientListIndexByName(HospitalList hospitalList[HOSPITAL_LIST_SIZE],
		char name[RECORDS_ITEM_LENGTH]) {
	for (int i = 0; i < HOSPITAL_LIST_SIZE; ++i) {
		if (hospitalList[i].firstLetter == tolower(name[0]))
			return i;
	}
	return -1;
}

void addPatient(Patient **head, Patient *patient) {

	if (*head == NULL) {
		*head = patient;
	} else {
		Patient *tmp = *head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = patient;
	}
}

void add(HospitalList *hospitalList, Patient *patient) {
	int index = findPatientListIndexByName(hospitalList, patient->name);
	if (index != -1) {
		addPatient(&(hospitalList[index].firstRecord), patient);
	}
}

void printRecord(HospitalList hospitalList) {
	printPatients(hospitalList.firstRecord, toupper(hospitalList.firstLetter));
}

void printRecords(HospitalList hospitalList[HOSPITAL_LIST_SIZE]) {
	printf("\n\n\n\n%4s %30s %30s %20s %30s", "List", "Name", "Surname",
			"Person Id", "Polyclinic");
	printf(
			"\n----------------------------------------------------------------------------------------------------------------------");
	for (int i = 0; i < HOSPITAL_LIST_SIZE; ++i) {
		printRecord(hospitalList[i]);
	}
}

Patient* createPatient(char *name, char *surname, int personId,
		char *polyclinic) {
	Patient *patient = (Patient*) malloc(sizeof(Patient));

	strcpy(patient->name, name);
	strcpy(patient->surname, surname);
	patient->personId = personId;
	strcpy(patient->polyclinic, polyclinic);
	patient->next = NULL;
	return patient;
}

void swap(Patient *a, Patient *b) {
	char name[RECORDS_ITEM_LENGTH];
	char surname[RECORDS_ITEM_LENGTH];
	int personId;
	char polyclinic[RECORDS_ITEM_LENGTH];

	personId = a->personId;
	strcpy(name, a->name);
	strcpy(surname, a->surname);
	strcpy(polyclinic, a->polyclinic);

	strcpy(a->name, b->name);
	strcpy(a->surname, b->surname);
	strcpy(a->polyclinic, b->polyclinic);
	a->personId = b->personId;

	strcpy(b->name, name);
	strcpy(b->surname, surname);
	strcpy(b->polyclinic, polyclinic);
	b->personId = personId;
}

void sortPatientByName(Patient **head) {
	Patient *node = *head, *temp = NULL;

	while (node != NULL) {
		temp = node;
		while (temp->next != NULL) {
			if (strcmp(temp->name, temp->next->name) > 0) {
				swap(temp, temp->next);
			}
			temp = temp->next;
		}
		node = node->next;
	}
}

void sortPatientBySurname(Patient **head) {
	Patient *node = *head, *temp = NULL;

	while (node != NULL) {
		temp = node;
		while (temp->next != NULL) {
			if (strcmp(temp->surname, temp->next->surname) > 0) {
				swap(temp, temp->next);
			}
			temp = temp->next;
		}
		node = node->next;
	}
}

void sortPatientByPolyclinic(Patient **head) {
	Patient *node = *head, *temp = NULL;

	while (node != NULL) {
		temp = node;
		while (temp->next != NULL) {
			if (strcmp(temp->polyclinic, temp->next->polyclinic) > 0) {
				swap(temp, temp->next);
			}
			temp = temp->next;
		}
		node = node->next;
	}
}

void sortRecordsByName(HospitalList *hospitalList) {
	for (int i = 0; i < HOSPITAL_LIST_SIZE; ++i) {
		sortPatientByName(&(hospitalList[i].firstRecord));
	}
}

void sortRecordsBySurname(HospitalList *hospitalList) {
	for (int i = 0; i < HOSPITAL_LIST_SIZE; ++i) {
		sortPatientBySurname(&(hospitalList[i].firstRecord));
	}
}

void sortRecordsByPolyclinic(HospitalList *hospitalList) {
	for (int i = 0; i < HOSPITAL_LIST_SIZE; ++i) {
		sortPatientByPolyclinic(&(hospitalList[i].firstRecord));
	}
}

Patient* find(Patient *head, char name[RECORDS_ITEM_LENGTH]) {
	Patient *temp = head;
	Patient *found = NULL;
	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) {
			found = temp;
			break;
		}
		temp = temp->next;
	}
	return found;
}

void delete(Patient **head, char name[RECORDS_ITEM_LENGTH]) {
	Patient *temp = *head;
	Patient *prev = NULL;

	if (strcmp(temp->name, name) == 0) {
		*head = (*head)->next;
		free(temp);
		return;
	}

	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) {
			prev->next = temp->next;
			free(temp);
			break;
		} else {
			prev = temp;
		}
		temp = temp->next;
	}
}

Patient* searchPatientByName(HospitalList *hospitalList,char name[RECORDS_ITEM_LENGTH]) {
	Patient *result = NULL;
	int index = findPatientListIndexByName(hospitalList, name);
	if (index != -1) {
		result = find(hospitalList[index].firstRecord, name);
	}
	return result;
}

void deletePatient(HospitalList *hospitalList, char name[RECORDS_ITEM_LENGTH]) {
	int index = findPatientListIndexByName(hospitalList, name);
	if (index != -1) {
		delete(&(hospitalList[index].firstRecord), name);
	}
}

void initHospitalList(HospitalList *hospitalList) {
	for (int index = 0, letter = 'a'; letter <= 'z'; index++, letter++) {
		hospitalList[index].firstLetter = (char) letter;
		hospitalList[index].firstRecord = NULL;
	}
}

void deleteRecord(HospitalList *hospitalList) {
	char nameToDelete[RECORDS_ITEM_LENGTH];
	printf("\nEnter patient name to delete : ");
	scanf("%s", nameToDelete);
	Patient *patientToDelete = searchPatientByName(hospitalList, nameToDelete);
	if (patientToDelete == NULL) {
		printf("Patient not found for delete with %s!", nameToDelete);
	} else {
		printf("%s founded!!\n", patientToDelete->name);
		printOnePatient(*patientToDelete);
		deletePatient(hospitalList, patientToDelete->name);
	}
}

void searchRecord(HospitalList *hospitalList) {
	char nameToSearch[RECORDS_ITEM_LENGTH];
	printf("\nEnter patient name to search : ");
	scanf("%s", nameToSearch);
	Patient *patientSearched = searchPatientByName(hospitalList, nameToSearch);
	if (patientSearched == NULL) {
		printf("Patient not found with %s!", nameToSearch);
	} else {
		printOnePatient(*patientSearched);
	}
}

int main() {

	HospitalList hospitalList[HOSPITAL_LIST_SIZE];
	initHospitalList(hospitalList);

	int choice;
	int flag = 1;

	while (1) {

		printf("\n");
		printf("\n ** MENU **");
		printf("\n 1 Add new record");
		printf("\n 2 Search record");
		printf("\n 3 Delete record");
		printf("\n 4 Sort records by name");
		printf("\n 5 Sort records by surname");
		printf("\n 6 Sort records by polyclinic");
		printf("\n 7 EXIT ");
		printf("\n Please select your choice : ");
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			if (flag == 1) {
				printf("\nTest Hasta Bilgileri Hazırlanıyor...");
				printf("\n yeni giriş için tekrar 1'e basınız ...");

				Patient *turan = createPatient("Tamer", "By", 1019000,"Orthodontics");
				Patient *tahsin = createPatient("Taner", "Ac", 1019001,"Endoscopy");
				Patient *muhteber = createPatient("Muhteber", "Aydin", 1902540,"Cardiology");
				Patient *taner = createPatient("Turan", "Aydin", 1019002,"Implant");
				Patient *tufan = createPatient("Zeynep", "Vural", 1019003, "Orthodontics");


				add(hospitalList, turan);
				add(hospitalList, tahsin);
				add(hospitalList, muhteber);
				add(hospitalList, taner);
				add(hospitalList, tufan);

				Patient *busra = createPatient("Busra", "Aydin", 1002000,"Implant");
				Patient *bugra = createPatient("Bugra", "Can", 1002001, "Endoscopy");
				Patient *fatmanur = createPatient("Fatmanur", "Karabacak", 1902540, "Orthodontics");
				Patient *feyza = createPatient("Feyza", "Yayık", 1999999, "Cardiology");

				add(hospitalList, busra);
				add(hospitalList, bugra);
				add(hospitalList, fatmanur);
				add(hospitalList, feyza);

				Patient *ahmet = createPatient("Ahmet", "Aydin", 1001000,"Cardiology");
				add(hospitalList, ahmet);

				Patient *can = createPatient("Can", "Yaman", 1003000,"Implant");
				add(hospitalList, can);
				flag = 0;
			} else {
				char name[RECORDS_ITEM_LENGTH];
				char surname[RECORDS_ITEM_LENGTH];
				int personId;
				char polyclinic[RECORDS_ITEM_LENGTH];
				printf("Enter name : ");
				scanf("%s", name);
				printf("Enter surname : ");
				scanf("%s", surname);
				printf("Enter person ID : ");
				scanf("%d", &personId);
				printf("Enter Polyclinic : ");
				scanf("%s", polyclinic);
				Patient *newPatient = createPatient(name, surname, personId,polyclinic);
				add(hospitalList, newPatient);

			}

			printRecords(hospitalList);

			break;
		case 2:
			searchRecord(hospitalList);
			break;
		case 3:
			deleteRecord(hospitalList);
			break;
		case 4:
			sortRecordsByName(hospitalList);
			printRecords(hospitalList);
			break;
		case 5:
			sortRecordsBySurname(hospitalList);
			printRecords(hospitalList);
			break;
		case 6:
			sortRecordsByPolyclinic(hospitalList);
			printRecords(hospitalList);
			break;
		case 7:
			printf("\nExited..");
			exit(-1);
		default:
			printf("\nDoğru seçim yapılamadı!!");
			break;
		}

	}

}
