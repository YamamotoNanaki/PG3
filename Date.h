#pragma once

struct Date
{
	static Date today;
	unsigned short year;
	unsigned short day;
	unsigned short month;
	//何月何日で表示
	void Draw();
	void Set();
	//今日と現在保持している日数のデータの30日以内の日数差を計算
	int DaysDifference();
	static void SetToday();
};

