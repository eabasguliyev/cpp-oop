#include <iostream>
#include <time.h>
#include <string>
#include <string.h>
#include <fstream>

namespace SmartPointers
{
	template <typename T>
	class UniquePointer
	{
		T* ptr;
	public:
		UniquePointer() :ptr(NULL) {}
		UniquePointer(T* ptr)
		{
			this->ptr = ptr;
		}

		UniquePointer(const UniquePointer& other) = delete;
		UniquePointer& operator=(const UniquePointer& other) = delete;

		UniquePointer(UniquePointer&& other)
		{
			this->ptr = other.ptr;
			other.ptr = NULL;
		}

		UniquePointer& operator=(UniquePointer&& other)
		{
			if (this != &other)
			{
				if (this->ptr != NULL)
				{
					delete this->ptr;
				}
				this->ptr = other.ptr;
				other.ptr = NULL;
			}
			return *this;
		}

		~UniquePointer()
		{
			delete this->ptr;
			this->ptr = NULL;
		}

		operator bool() const { return this->ptr != NULL; }

		T& operator*() const { return *this->ptr; }
		T* operator->() const { return this->ptr; }
	};

	template <typename T>
	class SharedPointer
	{
		T* address;
		size_t* count;
	
	public:
		SharedPointer() : address(NULL), count(NULL) {}
		explicit SharedPointer(T* address) :address(address), count(new size_t(1)) {}
		SharedPointer(const SharedPointer& other): address(other.address),
			count(other.count)
		{
			(*count)++;
		}
		SharedPointer& operator=(const SharedPointer& other)
		{
			if (this->count != NULL)
			{
				(*this->count)--;
				if (*this->count == 0)
				{
					delete this->address;
					delete this->count;
				}
			}
	
			this->address = other.address;
			this->count = other.count;
			(*this->count)++;
			return *this;
		}
		SharedPointer& operator=(T* other)
		{
			if (this->count != NULL)
			{
				(*this->count)--;
				if (*this->count == 0)
				{
					delete this->address;
					delete this->count;
				}
			}
	
			this->count = new size_t(1);
			this->address = other;
	
			return *this;
		}
		~SharedPointer()
		{
			if (this->count != NULL)
			{
				(*this->count)--;
				if (*this->count == 0)
				{
					delete this->address;
					delete this->count;
				}
			}
		}
	
		T* get() const { return this->address; }
	
		T& operator*() const { return *get(); };
	
		T* operator->() const { return get(); }
	};
}

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Resource& res)
	{
		out << "I am a resource\n";
		return out;
	}
};

namespace SP = SmartPointers;

namespace Time
{
	std::string getDate()
	{
		time_t now(time(0));
		tm new_time;
		localtime_s(&new_time, &now);
		return std::to_string(new_time.tm_mday) + '/' + std::to_string(new_time.tm_mon + 1) + '/' +
			std::to_string(new_time.tm_year + 1900) + ' ' + std::to_string(new_time.tm_hour) + ':' + std::to_string(new_time.tm_min);
	}
}

#define file_name "votes.txt"

class President
{
	std::string name;
	std::string country;
	size_t workPractise;
public:
	President() : name(""), country(""), workPractise(0) {}

	President(const std::string& name, const std::string& country, const size_t& workPractise)
	{
		setName(name);
		setCountry(country);
		setWorkPractise(workPractise);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	void setCountry(const std::string& country) { this->country = country; }
	std::string getCountry() const { return this->country; }
	void setWorkPractise(const size_t& workPractise) { this->workPractise = workPractise; }
	size_t getWorkPractise() const { return this->workPractise; }

	void showAllVotes() const
	{
		std::cout << readVotes() << std::endl;
	}

	std::string readVotes() const
	{
		std::ifstream fin(file_name);

		std::string text;
		if (fin.is_open())
		{

			while (!fin.eof())
			{
				std::string line;
				std::getline(fin, line);
				text.append(line + "\n");
			}
		}

		fin.close();
		return text;
	}
};

struct Candidate
{
	President* candidate;
	size_t* voteCount;
};

class Person
{
	std::string name;
	std::string surname;
	size_t age;
	std::string speciality;
	std::string sendVoteDateTime;
	Candidate* candidate;
public:
	static Candidate** candidates;
	static size_t candidate_count;

	Person() :name(""), surname(""), age(0), speciality(""),
		sendVoteDateTime(""), candidate(NULL) {}

	Person(const std::string& name, const std::string& surname, const size_t& age, const std::string& speciality)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setSpeciality(speciality);
	}

	void setName(const std::string& name) { this->name = name; }
	std::string getName() const { return this->name; }
	void setSurname(const std::string& surname) { this->surname = surname; }
	std::string getSurame() const { return this->surname; }
	void setSpeciality(const std::string& speciality) { this->speciality = speciality; }
	std::string getSpeciality() const { return this->speciality; }
	void setAge(const size_t& age) { this->age = age; }
	size_t getAge() const { return this->age; }
	void setVotedDateTime() { this->sendVoteDateTime = Time::getDate(); }
	std::string getVotedDateTime() const { return this->sendVoteDateTime; }

	void sendVote(President* candidate)
	{
		if (this->candidate == NULL)
		{
			if (checkCandidateInList(candidate))
			{
				Candidate* item = getCandidate(candidate);

				(*item->voteCount)++;
				this->candidate = new Candidate;
				this->candidate->candidate = item->candidate;
				this->candidate->voteCount = item->voteCount;
			}
			else
			{
				addCandidateToList(candidate);
				Candidate* item = getCandidate(candidate);

				this->candidate = new Candidate;
				this->candidate->candidate = item->candidate;
				this->candidate->voteCount = item->voteCount;
			}
			setVotedDateTime();
			writeToFile();
		}
	}
	bool checkCandidateInList(President* candidate) const
	{
		for (size_t i = 0; i < candidate_count; i++)
		{
			if (candidates[i]->candidate == candidate)
				return true;
		}
		return false;
	}
	void addCandidateToList(President* candidate)
	{
		size_t new_candidate_count = candidate_count + 1;

		auto new_candidates = new Candidate * [new_candidate_count];

		if (new_candidates)
		{
			if (candidate_count)
			{
				for (size_t i = 0; i < candidate_count; i++)
				{
					new_candidates[i] = candidates[i];
				}
				delete[] candidates;
			}
			
			new_candidates[candidate_count] = new Candidate;
			new_candidates[candidate_count]->candidate = candidate;
			new_candidates[candidate_count]->voteCount = new size_t(1);

			candidates = new_candidates;
			candidate_count = new_candidate_count;

		}
	}
	void deleteCandidateFromList(President* candidate)
	{
		if (candidate_count)
		{
			size_t new_candidate_count = candidate_count - 1;
			auto new_candidates = new Candidate * [new_candidate_count];

			for (size_t i = 0, j = 0; i < candidate_count; i++)
			{
				if (candidate == candidates[i]->candidate)
					delete candidates[i];
				else
					new_candidates[j++] = candidates[i];
			}
			delete[] candidates;
			candidate_count--;
			candidates = new_candidates;
		}
	}
	Candidate* getCandidate(President* candidate) const
	{
		for (size_t i = 0; i < candidate_count; i++)
		{
			if (candidates[i]->candidate == candidate)
				return candidates[i];
		}
		return NULL;
	}
	size_t getVoteCount() const { return *this->candidate->voteCount; }
	void writeToFile()
	{
		std::ofstream fout(file_name, std::ios_base::app);

		if (fout.is_open())
		{
			std::string text;
			text.append("Name: " + this->name + "\n");
			text.append("Surname: " + this->surname + "\n");
			text.append("Age: " + std::to_string(this->age) + "\n");
			text.append("Speciality: " + this->speciality + "\n");
			text.append("Voted to: " + this->candidate->candidate->getName() + "\n");
			text.append("Voted date time: " + this->sendVoteDateTime + "\n");
			text.append("\n");
			fout << text;
		}
		fout.close();
	}
	~Person()
	{
		(*this->candidate->voteCount)--;
		
		if ((*this->candidate->voteCount) == 0)
		{
			deleteCandidateFromList(this->candidate->candidate);
		}
		delete this->candidate;
	}
};

Candidate** Person::candidates = NULL;
size_t Person::candidate_count = NULL;

void main()
{
	// task 1
	/*SP::UniquePointer<Resource>  res1{ new Resource() };
	SP::UniquePointer<Resource> res2{};

	std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
	std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

	res2 = std::move(res1);
	std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
	std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

	std::cout << *res1 << std::endl;*/

	// task 2

	President* presidentA = new President("Joe Biden", "USA", 30);
	President* presidentB = new President("Donald Trump", "USA", 31);

	Person* p1 = new Person("Elgun", "Abasquliyev", 20, "Software Developer");
	Person* p2 = new Person("Abil", "Yaqublu", 19, "Network Administrator");
	Person* p3 = new Person("Resul", "Osmanli", 18, "Software Developer");
	Person* p4 = new Person("Ismayil", "Memmedov", 21, "Business Managment");
	Person* p5 = new Person("Ilqar", "Kerimli", 24, "Cybersec");



	p1->sendVote(presidentA);
	std::cout << "Voted!" << std::endl;
	std::cout << "Time: " << p1->getVotedDateTime() << std::endl;
	std::cout << "Vote count: " << p1->getVoteCount() << std::endl;
	std::cin.get();
	p2->sendVote(presidentA);
	std::cout << "Voted!" << std::endl;
	std::cout << "Time: " << p2->getVotedDateTime() << std::endl;
	std::cout << "Vote count: " << p2->getVoteCount() << std::endl;
	std::cin.get();
	p3->sendVote(presidentA);
	std::cout << "Voted!" << std::endl;
	std::cout << "Time: " << p3->getVotedDateTime() << std::endl;
	std::cout << "Vote count: " << p3->getVoteCount() << std::endl;
	std::cin.get();
	p4->sendVote(presidentB);
	std::cout << "Voted!" << std::endl;
	std::cout << "Time: " << p4->getVotedDateTime() << std::endl;
	std::cout << "Vote count: " << p4->getVoteCount() << std::endl;
	std::cin.get();
	p5->sendVote(presidentB);
	std::cout << "Voted!" << std::endl;
	std::cout << "Time: " << p5->getVotedDateTime() << std::endl;
	std::cout << "Vote count: " << p5->getVoteCount() << std::endl;
	std::cin.get();

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	//std::cout << "Vote count: " << p5->getVoteCount() << std::endl;
	delete p5;
	
	std::cout << "Candidate 1: " << presidentA->getName() << std::endl;
	std::cout << "Candidate 2: " << presidentB->getName() << std::endl;


	std::cin.get();

	system("CLS");

	presidentA->showAllVotes();

	delete presidentA;
	delete presidentB;

}