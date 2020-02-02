#include <vector>
#include <cstddef>
#include <numeric>
#include <iostream>

typedef unsigned long long ui64;
#define distance(x, y) (x > y ? x - y -1 : y - x -1)


struct TBar {
    ui64 Position;
    ui64 Height;
};

struct TTaskResult {
    ui64 WaterAmount = 0;
    TBar Bar = {0, 0};
    TBar LeftBound = {0, 0};
    TBar RightBound = {0, 0};
    ui64 LeftDrop = 0;  // here sum of what we have to subtract from new water level: bars and water already accounted
    ui64 RightDrop = 0;

    TTaskResult(ui64 position, ui64 height)
        : Bar{.Position=position, .Height=height}
        , LeftBound{.Position=position, .Height=height}
        , RightBound{.Position=position, .Height=height}
    {}

    TTaskResult() {}
};

ui64 WaterBetween(const TTaskResult &lower, const TTaskResult &higher, bool isLeft = true) {
    TBar boundBar = isLeft ? higher.LeftBound : higher.RightBound;
    ui64 water;
    if (lower.Bar.Height > boundBar.Height) {
        water = lower.Bar.Height * distance(lower.Bar.Position, higher.Bar.Position);
        water -= isLeft ? (lower.RightDrop + higher.LeftDrop) : (higher.RightDrop + lower.LeftDrop);
    } else {
        water = lower.Bar.Height * distance(lower.Bar.Position, boundBar.Position);
        water -= isLeft ? lower.RightDrop : lower.LeftDrop;
    }
    return water;
}

TTaskResult Solve(const std::vector<TTaskResult> &bars) {
    if (bars.empty()) {
        return TTaskResult();
    } else if (bars.size() == 1) {
        return bars.front();
    }

    auto result = TTaskResult();
    result.WaterAmount = std::accumulate(bars.begin(), bars.end(), 0,
                                         [](ui64 r, const TTaskResult &task) { return r + task.WaterAmount; });
    size_t leftHighest = 0, rightHighest = bars.size() - 1;
    size_t left = 0, right = bars.size() - 1;
    ui64 leftDrop = 0, rightDrop = 0;
    while (left != right) {
        if (bars[leftHighest].Bar.Height < bars[rightHighest].Bar.Height) {
            left++;
            if (bars[leftHighest].Bar.Height > bars[left].Bar.Height) {
                leftDrop += bars[left].LeftDrop + bars[left].RightDrop + bars[left].Bar.Height;
            } else {
                ui64 water = WaterBetween(bars[leftHighest], bars[left], true);
                result.WaterAmount += water - leftDrop;
                result.LeftDrop += water + bars[leftHighest].Bar.Height + bars[leftHighest].RightDrop + bars[left].LeftDrop;
                leftHighest = left;
                leftDrop = 0;
            }
        } else {
            right--;
            if (bars[right].Bar.Height < bars[rightHighest].Bar.Height) {
                rightDrop += bars[right].Bar.Height + bars[right].LeftDrop + bars[right].RightDrop;
            } else {
                ui64 water = WaterBetween(bars[rightHighest], bars[right], false);
                result.WaterAmount += water - rightDrop;
                result.RightDrop += water + bars[rightHighest].Bar.Height + bars[rightHighest].LeftDrop + bars[right].RightDrop;
                rightHighest = right;
                rightDrop = 0;
            }

        }
    }
    result.LeftDrop += bars.front().LeftDrop;
    result.LeftBound = bars.front().LeftBound;
    result.RightDrop += bars.back().RightDrop;
    result.RightBound = bars.back().RightBound;
    result.Bar = bars[left].Bar;
    return result;
}

ui64 SumWater(const std::vector<ui64> &bars) {
    static const size_t BATCH_SIZE = 4;
    std::vector<TTaskResult> batch;
    std::vector<TTaskResult> result;
    for (ui64 i = 0; i < bars.size(); ++i) {
        batch.emplace_back(i, bars[i]);
        if (batch.size() == BATCH_SIZE) {
            result.push_back(Solve(batch));
            batch.clear();
        }
    }
    if (!batch.empty()) {
        result.push_back(Solve(batch));
    }
    auto taskResult = Solve(result);
    return taskResult.WaterAmount;
}

int main() {
    std::cout << SumWater(std::vector<ui64>{8,7,2,5,6}) << std::endl;
}