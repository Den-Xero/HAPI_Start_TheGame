#pragma once
class Border
{
	private:

	public:
		int LeftSide{ 0 }, RightSide{ 0 }, TopSide{ 0 }, BottomSide{0};

		Border() {};
		Border(int L, int R, int T, int B) :
			LeftSide(L), RightSide(R), TopSide(T), BottomSide(B) {}

		int Width() const { return RightSide - LeftSide; }
		int Height() const { return BottomSide - TopSide; }

		void Translate(int TX, int TY)
		{
			LeftSide += TX;
			RightSide += TX;
			TopSide += TY;
			BottomSide += TY;
		}

		void ClipBorders(const Border& other)
		{
			if (LeftSide < other.LeftSide)
				LeftSide = other.LeftSide;

			if (RightSide > other.RightSide)
				RightSide = other.RightSide;

			if (TopSide < other.TopSide)
				TopSide = other.TopSide;

			if (BottomSide > other.BottomSide)
				BottomSide = other.BottomSide;
		}

		void IsTheSpriteOffScreen()
		{
			if (RightSide < 0)
				RightSide = 0;

			if (LeftSide > 64)
				LeftSide = 64;

			if (TopSide > 64)
				TopSide = 64;

			if (BottomSide < 0)
				BottomSide = 0;
		}
};

